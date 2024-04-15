#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> mp(128, 0);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) mp[str[i]]++;
    int cnt = 0;
    for (int i = 0; i < 128; ++i)
        if (mp[i]) cnt++;

    cout << cnt << endl;

    return 0;
}