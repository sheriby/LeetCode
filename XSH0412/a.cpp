#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    unordered_set<string> st;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        if (!st.count(str)) {
            cout << str << endl;
            st.insert(str);
        }
    }

    return 0;
}