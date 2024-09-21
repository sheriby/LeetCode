#include <bits/stdc++.h>
using namespace std;

double min_diff(double a, double b) {
    return min(abs(a - b), 360 - abs(a - b));
}

// 14%
int main() {
    int n, m;
    cin >> n >> m;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double max_val = 0;
    double diff = 0;
    int res = 0;
    for (int a = m; a >= 1; a--) {
        double max_diff = 0;
        if (a == 1)
            max_diff = 180;
        else {
            do {
                double cur_diff = 360;
                vector<double> arr2(arr.begin(), arr.begin() + a);
                sort(arr2.begin(), arr2.end());
                for (int i = 0; i < a - 1; ++i) {
                    cur_diff = min(cur_diff, min_diff(arr2[i], arr2[i + 1]));
                }
                cur_diff = min(cur_diff, min_diff(arr2[a - 1], arr2[0]));
                max_diff = max(max_diff, cur_diff);
            } while (next_permutation(arr.begin(), arr.end()));
        }
        double val =
            (1.0 / (2 * m) + 1.0 / (2 * a) - (180 - max_diff) / (360 * m * a)) *
            a;
        if (val > max_val) {
            max_val = val;
            diff = max_diff;
            res = a;
        }
    }
    printf("%.5lf\n", diff);
    cout << res << endl;
    return 0;
}