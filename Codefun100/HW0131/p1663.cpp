#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int nlen;
int n;
void dfs(int idx, int val, vector<int>& path) {
    if (idx >= nlen) {
        if (path.size()) {
            if (val > path.back()) {
                cout << n << "=";
                for (int i = 0; i < path.size() - 1; ++i) {
                    cout << path[i] << "*";
                }
                cout << path.back() << "*" << val << endl;
            }
        } else {
            cout << n << "=" << n << endl;
        }
        return;
    }
    if (val == nums[idx]) {
        cout << n << "=";
        for (int j = 0; j < path.size() - 1; ++j) {
            cout << path[j] << "*";
        }
        cout << path.back() << "*" << val << endl;
        return;
    } else if (val % nums[idx] == 0) {
        path.push_back(nums[idx]);
        dfs(idx, val / nums[idx], path);  // 选
        path.pop_back();
    }
    dfs(idx + 1, val, path);  // 不选
}

int main() {
    cin >> n;
    vector<int> path;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) nums.push_back(i);
    }
    nlen = nums.size();
    dfs(0, n, path);

    return 0;
}