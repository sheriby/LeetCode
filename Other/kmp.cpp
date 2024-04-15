#include <bits/stdc++.h>
using namespace std;

void cal_next(string sub, vector<int>& next) {
    int len = sub.size();
    next[0] = -1;  // 初始化第0位
    int i = 0, j = -1;
    while (i < len) {
        if (j == -1 || sub[i] == sub[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}

int kmp_search(string str, string sub) {
    int str_len = str.size(), sub_len = sub.size();
    vector<int> next(sub_len);
    cal_next(sub, next);
    int i = 0, j = 0;
    while (i < str_len && j < sub_len) {
        if (j == -1 || str[i] == sub[j])
            i++, j++;
        else
            j = next[j];
    }
    if (j == sub_len)
        return i - sub_len;
    else
        return -1;
}

int main() {
    string str = "ababbaba ababaa";
    string sub = "ababa";
    int res = kmp_search(str, sub);
    cout << res << endl;

    return 0;
}
// ababbaba
//   ababa
