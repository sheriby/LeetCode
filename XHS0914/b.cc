#include <bits/stdc++.h>
using namespace std;

#define int long long

void sortbig(int &a, int &b, int &c) {
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
}
void sortsmall(int &a, int &b, int &c) {
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
}

int32_t main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        // ensure x < y < z
        int max_ans = 0;
        sortbig(x, y, z);
        for (int i = 1; i <= z; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (k >= i * j && k % (i * j) == 0) {
                    int t = k / (i * j);
                    if (x >= t)
                        max_ans = max(max_ans,
                                      (x - t + 1) * (z - i + 1) * (y - j + 1));
                } else if (k < i * j)
                    break;
            }
        }
        sortsmall(x, y, z);
        for (int i = 1; i <= z; ++i) {
            for (int j = 1; j <= y; ++j) {
                if (k >= i * j && k % (i * j) == 0) {
                    int t = k / (i * j);
                    if (x >= t)
                        max_ans = max(max_ans,
                                      (x - t + 1) * (z - i + 1) * (y - j + 1));
                } else if (k < i * j)
                    break;
            }
        }
        cout << max_ans << endl;
    }
    return 0;
}