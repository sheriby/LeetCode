#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> logs(n);
    for (int i = 0; i < n; ++i) cin >> logs[i];
    unordered_map<string, deque<int>> log_same;
    unordered_map<string, deque<int>> log_sim;

    for (int i = 0; i < n; ++i) {
        string str = logs[i];
        int idx = 0;
        while (str[idx] != ':') idx++;
        int log_time = stoi(str.substr(0, idx));
        string same_str = str.substr(idx + 1);
        string sim_str = "";
        for (int i = idx + 1; i < str.size(); ++i)
            if (!isdigit(str[i])) sim_str += str[i];

        deque<int>& same = log_same[same_str];
        deque<int>& sim = log_sim[sim_str];
        if (same.empty()) {
            same.push_back(log_time);
            sim.push_back(log_time);
        } else {
            if (log_time - same.back() < 10)  // 最近的相同是否在10ms内
                cout << logs[i] << endl;
            else if (sim.size() < 9) {  // 放进去也还没有10个相似的
                same.push_back(log_time);
                sim.push_back(log_time);
            } else if (log_time - sim.front() < 100)  // 最近100ms有9个相似的
                cout << logs[i] << endl;
            else {  // 相似的是100毫秒之外的
                while (sim.size() && log_time - sim.front() >= 100) {
                    sim.pop_front();
                    same.pop_front();
                }
                if (sim.size() < 9) {
                    sim.push_back(log_time);
                    same.push_back(log_time);
                } else {
                    cout << logs[i] << endl;
                }
            }
        }
    }
    return 0;
}