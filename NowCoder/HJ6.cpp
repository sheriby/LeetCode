#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    int num = 2;
    // 寻找一个数的因数，只需要 i * i <= num 就行了
    // 11 * 13 => 找到11，剩余13
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            while (num % i == 0) {
                cout << i << " ";
                num /= i;
            }
        }
    }
    if (num != 1) cout << num << endl;

    return 0;
}