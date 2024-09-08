#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long cost_odd = 0, cost_even = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cost_odd += arr[i] + 1;
        } else {
            cost_even += arr[i] + 1;
        }
    }
    cout << min(cost_odd, cost_even) << endl;
    return 0;
}