#include <bits/stdc++.h>
using namespace std;

int sunday(string str, string sub) {
    int str_len = str.size(), sub_len = sub.size();
    vector<int> move(128, sub_len + 1);  // 没有出现移动模式串长度+1
    for (int i = 0; i < sub_len; ++i)
        move[sub[i]] = sub_len - i;  // 出现存放到尾部的距离

    int i = 0, j = 0;
    while (i < str_len && j < sub_len) {
        if (str[i] == sub[j])
            i++, j++;
        else {
            i += move[str[i + sub_len]];
            j = 0;
        }
    }
    if (j == sub_len) return i - sub_len;
    return -1;
}

int main() {
    string str = "ababbaba ababaa";
    string sub = "ababa";
    int res = sunday(str, sub);
    cout << res << endl;

    return 0;
}
// ababbaba
//   ababa
