#include <bits/stdc++.h>
using namespace std;

// ac
int main() {
    int n;
    cin >> n;
    vector<int> vote(11, 0);
    for (int i = 0; i < n; i++) {
        int expcot = 0, vote_cot = 0;
        vector<int> vote_arr;
        for (int j = 1; j <= 10; j++) {
            int x;
            cin >> x;
            if (x != 0)
                expcot++;
            if (x == 2) {
                vote_cot++;
                vote_arr.push_back(j);
            }
        }
        if (expcot >= 3 && vote_cot + 2 <= expcot && vote_cot <= 5) {
            for (int j = 0; j < vote_arr.size(); j++) {
                vote[vote_arr[j]]++;
            }
        }
    }
    int max_ele = -1;
    for (int i = 1; i <= 10; i++) {
        if (vote[i] > max_ele) {
            max_ele = vote[i];
        }
    }
    for (int i = 1; i <= 10; i++) {
        if (vote[i] == max_ele) {
            cout << i << " ";
        }
    }
    return 0;
}