#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    str[len-1] += 1;
    if (str[len-1] != 'z' + 1) {
        cout << str << endl;
        return 0;
    }
    str[len-1] = 'a';
    int jw = 1;
    for (int i = len-2; i >=0; --i) {
        if (str[i] == 'z' && jw) {
            str[i] = 'a';
        } else {
            str[i] += 1;
            jw = 0;
            break;
        }
    }
    if (jw) cout << -1 << endl;
    else cout << str << endl;
    return 0;
}