#include <bitset>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;

constexpr int mod = 1e3 + 1;
bitset<mod> bs;

int myhash(string s, int seed) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = ((ll)res * seed + s[i]) % mod;
    }
    return res;
}

bool exist(string s) {
    int a = myhash(s, 125), b = myhash(s, 239), c = myhash(s, 347);
    cout << a << "@" << b << "@" << c << endl;
    if (bs[a] && bs[b] && bs[c]) return true;
    return false;
}

void insert(string s) {
    int a = myhash(s, 125), b = myhash(s, 239), c = myhash(s, 347);
    cout << a << "#" << b << "#" << c << endl;
    bs.set(a), bs.set(b), bs.set(c);
}

int main() {
    string a = "hello world";
    insert(a);
    string b = "helloworld";
    insert(b);
    string c = "helloworld";
    if (exist(c)) {
        cout << "exist" << endl;
    } else {
        cout << "not exist" << endl;
    }
}