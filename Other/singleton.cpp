#include <bits/stdc++.h>
using namespace std;

class Singleton {
   public:
    static Singleton &getInstance() {
        static Singleton singleton_;
        return singleton_;
    }

   private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

int main() {
    Singleton *s1 = &Singleton::getInstance();
    Singleton *s2 = &Singleton::getInstance();
    printf("%x\n", s1);
    printf("%x\n", s2);

    return 0;
}