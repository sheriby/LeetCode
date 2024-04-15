#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    stack<int> st;
    int num;
    while (cin >> num) nums.push_back(num);
    int len = nums.size();

    vector<int> sums;
    int flag = false, val;
    int i = 0;
    while (i < len) {
        if (!flag) val = nums[i];
        flag = false;
        if (st.empty()) {
            st.push(val);
            i++;
            continue;
        }
        if (val == st.top()) {
            st.pop();
            val *= 2;
            flag = true;
        } else {
            // 等于和
            int sum = 0;
            stack<int> tmp;
            while (st.size() && sum < val) {
                int front = st.top();
                st.pop();
                tmp.push(front);
                sum += front;
            }
            if (sum == val) {
                val *= 2;
                flag = true;
            } else {
                while (!tmp.empty()) {
                    st.push(tmp.top());
                    tmp.pop();
                }
                st.push(val);
                i++;
            }
        }
    }
    while (st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}