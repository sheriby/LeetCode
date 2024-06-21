#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int cnt = 0;

string remove(string str) {
    string tmp;
    tmp += str[0];
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1])
            cnt++;
        else
            tmp += str[i];
    }
    return tmp;
}

int main() {
    cin >> n;
    cin >> str;
    while (true) {
        string tmp = remove(str);
        if (tmp == str) {
            cout << cnt << endl;
            break;
        }
        str = tmp;
    }
}