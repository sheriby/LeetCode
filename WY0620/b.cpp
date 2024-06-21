#include <bits/stdc++.h>
using namespace std;

int builds[401][4];
int n, A, B, C;
int max_profit = 0;

void dfs(int cur, int profit, int a, int b, int c) {
    max_profit = max(max_profit, profit);
    if (cur == n)
        return;
    if (a >= builds[cur][0] && b >= builds[cur][1] && c >= builds[cur][2])
        dfs(cur + 1, profit + builds[cur][3], a - builds[cur][0],
            b - builds[cur][1], c - builds[cur][2]);
    dfs(cur + 1, profit, a, b, c);
}

int main() {
    cin >> n >> A >> B >> C;
    for (int i = 0; i < n; i++)
        cin >> builds[i][0] >> builds[i][1] >> builds[i][2] >> builds[i][3];
    dfs(0, 0, A, B, C);
    cout << max_profit << endl;
    return 0;
}