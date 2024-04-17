#include <functional>
#include <iostream>
using namespace std;

template <typename T>
class ArrayDeletor {
   public:
    void operator()(T* ptr) const { delete[] ptr; }
};

template <typename T>
class DefaultDeletor {
   public:
    void operator()(T* ptr) const { delete ptr; }
};

template <typename T, typename Deletor>
class RefCnt {
   public:
    RefCnt(T* ptr = nullptr) : cnt(1), ptr(ptr), del(Deletor()) {}
    void addRef() { ++cnt; };
    void delRef() {
        if (--cnt == 0 && ptr) {
            del(ptr);
        }
    }
    int getCount() const { return cnt; }

   private:
    int cnt;
    T* ptr;
    Deletor del;
};

template <typename T, typename Deletor = DefaultDeletor<T>>
class SharedPtr {
   public:
    SharedPtr(T* ptr = nullptr) : ptr(ptr), cnt(new RefCnt<T, Deletor>(ptr)) {}
    SharedPtr(const SharedPtr<T, Deletor>& s) : ptr(s.ptr), cnt(s.cnt) {
        cnt->addRef();
    }
    SharedPtr<T, Deletor> operator=(const SharedPtr<T, Deletor>& s) {
        if (&s == this) return *this;
        this->cnt->delRef();
        this->ptr = s.ptr;
        this->cnt = s.cnt;
        this->cnt->addRef();
        return *this;
    }
    ~SharedPtr() { this->cnt->delRef(); }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T& operator[](int i) { return *(ptr + i); }
    int getCount() const { return cnt->getCount(); };

   private:
    T* ptr;
    RefCnt<T, Deletor>* cnt;
};

int main() {
    SharedPtr<int> p1(new int);
    cout << p1.getCount() << endl;
    SharedPtr<int> p2(p1);
    cout << p1.getCount() << endl;
    SharedPtr<int, ArrayDeletor<int>> p3(new int[10]);
    for (int i = 0; i < 10; ++i) p3[i] = i;
    for (int i = 0; i < 10; ++i) cout << p3[i] << " ";
}