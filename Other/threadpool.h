#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <cassert>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

struct Pool {
    std::mutex mutex;
    std::conditional_variable cond;
    bool is_close;
    std::queue<std::function<void()>> taskQue;
};

class ThreadPool {
   public:
    explicit ThreadPool(int threadNums)
        : threadNums_(threadNums), pool(std::make_shared<Pool>()) {
        assert(threadNums_ > 0);
        for (int i = 0; i < threadNums_; ++i) {
            std::thread([&]() {
                std::unique_lock<std::mutex> lock(pool_->mutex);
                while (true) {
                    if (!pool_->taskQue.empty()) {
                        auto task = std::move(pool_->taskQue.front());
                        pool_->taskQue.pop();
                        lock.unlock();
                        task();
                        lock.lock();
                    } else if (pool_->is_close) {
                        break;
                    } else {
                        pool_->cond.wait(lock);
                    }
                }
            }).detach();
        }
    }

    ~ThreadPool() {
        if (pool_) {
            std::lock_guard<std::mutex> lock(pool_->mutex);
            pool_->is_close = true;
            pool_->cond->notify_all();
        }
    }

    template <typename T>
    void addTask(T&& task) {
        if (pool_) {
            std::lock_guard<std::mutex> lock(pool_->mutex);
            pool_->taskQue.emplace(std::forward<T>(task));
            pool_->cond->notify_one();
        }
    }

   private:
    std::shared_ptr<Pool> pool;
    int threadNums_
};

#endif