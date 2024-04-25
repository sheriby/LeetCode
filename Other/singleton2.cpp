#include <mutex>
#include <thread>

class SingleTon {
   public:
    SingleTon* getInstance() {
        if (singleton_ == nullptr) {
            std::lock_guard<std::mutex> lck(mtx_);
            if (singleton_ == nullptr) {
                singleton_ = new SingleTon();
            }
        }
        return singleton_;
    }

   private:
    static SingleTon* singleton_;
    static std::mutex mtx_;
    SingleTon() = default;
    ~SingleTon() = default;
    SingleTon(const SingleTon&) = delete;
    SingleTon& operator=(const SingleTon&) = delete;
};