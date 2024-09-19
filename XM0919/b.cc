#include <bits/stdc++.h>
using namespace std;

bool arrs(vector<int> a, vector<int> b) {
    a[0] = min(a[0], b[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1] && b[i] < a[i - 1])
            return false;
        else if (b[i] >= a[i - 1] && a[i] >= a[i - 1]) {
            a[i] = min(a[i], b[i]);
        } else if (b[i] >= a[i - 1]) {
            a[i] = b[i];
        }
    }
    return true;
}

bool arrj(vector<int> a, vector<int> b) {
    a[0] = max(a[0], b[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > a[i - 1] && b[i] > a[i - 1])
            return false;
        else if (b[i] <= a[i - 1] && a[i] <= a[i - 1]) {
            a[i] = max(a[i], b[i]);
        } else if (b[i] <= a[i - 1]) {
            a[i] = b[i];
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (arrs(a, b) || arrs(b, a) || arrj(a, b) || arrj(b, a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}