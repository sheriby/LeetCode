#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // f(0) = 0, f(1) = 1;
    int fib(int n) {
        if (!n) return 0;
        int p = 0, q = 1;
        for (int i = 0; i < n; ++i) {
            int tmp = q;
            q += p;
            p = tmp;
        }
        return q;
    }
};