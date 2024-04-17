#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Function {};

template <typename R, typename... T>
class Function<R(T...)> {
   public:
    using PFUNC = R (*)(T...);

    Function(PFUNC pfunc) : _pfunc(pfunc) {}
    R operator()(T... args) { return _pfunc(args...); }

   private:
    PFUNC _pfunc;
};

int sum(int a, int b) { return a + b; }

void print(string str) { cout << str << endl; }

int main() {
    Function<int(int, int)> fn = sum;
    cout << fn(1, 2) << endl;
    Function<void(string)> fn2 = print;
    fn2("hello world");
}
