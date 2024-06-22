// lru
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LRU {
   private:
    list<T> cache;
    using ListIter = typename list<T>::iterator;
    unordered_map<T, ListIter> hash;
    int capacity;

   public:
    LRU(int c) : capacity(c) {}

    void insert(T key) {
        if (hash.find(key) != hash.end()) {
            // 如果键已经存在，先删除原来的位置
            cache.erase(hash[key]);
        } else if (cache.size() >= capacity) {
            // 如果缓存已满，删除链表尾部的键值对
            T last = cache.back();
            cache.pop_back();
            hash.erase(last);
        }
        // 将新的键值对插入到链表头部
        cache.push_front(key);
        hash[key] = cache.begin();
    }

    void display() {
        for (auto it = cache.begin(); it != cache.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    // LRU<int> lruCache(3);
    // lruCache.insert(1);
    // lruCache.insert(2);
    // lruCache.insert(3);
    // lruCache.display();
    // lruCache.insert(4);
    // lruCache.display();
    // lruCache.insert(1);
    // lruCache.display();

    LRU<string> lruCache2(2);
    lruCache2.insert("a");
    lruCache2.insert("b");
    lruCache2.display();
    lruCache2.insert("c");
    lruCache2.display();
    lruCache2.insert("d");
    lruCache2.display();
    return 0;
}