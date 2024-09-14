#include <bits/stdc++.h>
using namespace std;

int pri(char op) { return op == '+' ? 0 : 1; }

int alyop(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else {
        return a * b;
    }
}

int cal(string str) {
    stack<int> num_st;
    stack<char> op_st;
    for (int i = 0; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + str[i] - '0';
                ++i;
            }
            --i;
            num_st.push(num);
        } else {
            while (!op_st.empty() && pri(op_st.top()) >= pri(str[i])) {
                int b = num_st.top();
                num_st.pop();
                int a = num_st.top();
                num_st.pop();
                char op = op_st.top();
                op_st.pop();
                num_st.push(alyop(a, b, op));
            }
            op_st.push(str[i]);
        }
    }
    while (op_st.size()) {
        int b = num_st.top();
        num_st.pop();
        int a = num_st.top();
        num_st.pop();
        char op = op_st.top();
        op_st.pop();
        num_st.push(alyop(a, b, op));
    }
    return num_st.top();
}

int rightOP(string str) {
    int eqpos;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '=') {
            eqpos = i;
            break;
        }
    }
    string left = str.substr(0, eqpos);
    string right = str.substr(eqpos + 1);
    return cal(left) == cal(right);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        if (rightOP(str)) {
            cout << "Yes" << endl;
            continue;
        }
        string ans;
        int flag = false;
        for (int i = 0; i < str.size(); ++i) {
            if (isdigit(str[i])) {
                for (int j = 0; j < 10; ++j) {
                    char tmp = '0' + i;
                    ans = str.substr(0, i) + tmp + str.substr(i);
                    if (rightOP(ans)) {
                        flag = true;
                        cout << "Yes" << endl;
                        goto end;
                    }
                    ans = str.substr(0, i + 1) + tmp + str.substr(i + 1);
                    if (rightOP(ans)) {
                        flag = true;
                        cout << "Yes" << endl;
                        goto end;
                    }
                }
            }
        }
    end:
        if (!flag)
            cout << "No" << endl;
    }
}