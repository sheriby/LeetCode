#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> diff(n+1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }
    int cnt = 0;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] + diff[i];
        if (arr[i] == m) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}