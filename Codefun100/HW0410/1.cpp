#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str) {
    vector<string> res;
    int start = 0;
    for (int i = 1; i <= str.size(); ++i) {
        if (i == str.size() || str[i] == ',') {
            res.push_back(str.substr(start, i - start));
            start = i + 1;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> users(n);
    vector<string> factors(n);
    vector<int> times(n);
    unordered_map<string, vector<int>> user_mp;
    string tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        vector<string> strs = split(tmp);
        users[i] = strs[1];
        factors[i] = strs[2];
        times[i] = stoi(strs[3]);
        user_mp[users[i]].push_back(i);
    }

    int m;
    cin >> m;
    string factor;
    int price;
    unordered_map<string, int> price_mp;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        vector<string> strs = split(tmp);
        factor = strs[0];
        price = stoi(strs[1]);
        price_mp[factor] = price;
    }
    vector<pair<int, string>> users_res;
    for (auto user : user_mp) {
        vector<int> list = user.second;
        int sum_price = 0;
        for (auto idx : list) {
            if (times[idx] > 0 && times[idx] < 100 &&
                price_mp.count(factors[idx])) {
                sum_price += price_mp[factors[idx]] * times[idx];
            }
        }
        users_res.push_back({sum_price, user.first});
    }
    sort(users_res.begin(), users_res.end());
    for (auto user : users_res) {
        cout << user.second << "," << user.first << endl;
    }
    return 0;
}