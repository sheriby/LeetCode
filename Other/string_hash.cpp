#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int seed = 233;

int str_hash(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) res = ((ll)(res)*seed + s[i]) % mod;
    return res;
}

int main() {
    string s1 = "abcdefab";
    string s2 = "abcdefab";
    cout << str_hash(s1) << endl;
    cout << str_hash(s2) << endl;

    return 0;
}