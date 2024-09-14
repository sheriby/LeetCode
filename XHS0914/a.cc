#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ull> num(n);
    ull ans = 0;
    unordered_map<ull, ull> mymap;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mymap[num[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (num[i] == (num[i] ^ k) && mymap[num[i]]) {
            ans += (mymap[num[i]] - 1) * mymap[num[i]];
            mymap[num[i]] = 0;
        } else if (mymap.count(num[i]) && mymap.count(num[i] ^ k)) {
            ans += mymap[num[i]] * mymap[num[i] ^ k];
            mymap[num[i]] = 0;
            mymap[num[i] ^ k] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}