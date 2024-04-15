#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    char ch, och;
    getline(cin, str);
    cin >> ch;
    if (ch >= 'a') ch -= 32;
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i) {
        char tmp = str[i];
        if (tmp >= 'a') tmp -= 32;
        if (tmp == ch) cnt++;
    }

    cout << cnt << endl;

    return 0;
}