#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> matrix;
class Solution {
   public:
    //   [f(n+1)]   [1 1][ f(n) ]
    //   |      | = |   ||      |
    //   [ f(n) ]   [1 0][f(n-1)]

    //   [f(n+1)]   [1 1]^n[f(1)]
    //   |      | = |   |  |    |
    //   [ f(n) ]   [1 0]  [f(0)]
    int climbStairs(int n) {
        matrix a = {{1, 1}, {1, 0}};
        a = matrix_power(a, n);
        return a[0][0];
    }

   private:
    // c = a * b
    matrix matrix_mutilply(matrix& a, matrix& b) {
        int n = a.size();
        matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    // a = a ^ n
    matrix matrix_power(matrix& a, int p) {
        int n = a.size();
        matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while (p) {
            if (p & 1) res = matrix_mutilply(res, a);
            a = matrix_mutilply(a, a);
            p >>= 1;
        }
        return res;
    }
};