#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // set的底层是红黑树，自带排序和去重
    set<int> st;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        st.insert(num);
    }
    for (auto i : st) cout << i << endl;

    return 0;
}