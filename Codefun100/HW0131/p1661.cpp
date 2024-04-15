#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> mp;
    vector<string> num;
    string str;
    cin >> str;
    int start = 0, len = str.size();
    for (int i = 0; i <= len; ++i) {
        if (i == len || str[i] == ',') {
            num.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    len = num.size();
    for (int i = 0; i < len; ++i) {
        if (++mp[num[i]] > len / 2) {
            cout << num[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}