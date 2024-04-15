#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    // 读取一行的输入
    getline(cin, str);
    int len = str.size();
    int i;
    for (i = len - 1; i >= 0; --i) {
        if (str[i] == ' ') break;
    }
    cout << len - 1 - i << endl;
    return 0;
}