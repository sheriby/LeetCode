#include <bits/stdc++.h>
using namespace std;

bool no_win(vector<int>& arr) {
    if (arr.size() == 1) return false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 1) {
            return false;
        }
    }
    return true;
}

int solve(vector<int>& arr) {
    if (no_win(arr)) return -1;
    else return 1;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    for (int i = 0; i < q; i++) {
        char op;
        int l, r, x;
        cin >> op >> l >> r >> x;
        for (int j = l - 1; j < r; j++) {
            if (op == '+')
                arr[j] += x;
            else if(op == '-')
                arr[j] -= x;
        }
        cout << solve(arr) << endl;
    }
    return 0;
}
