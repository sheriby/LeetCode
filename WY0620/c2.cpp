#include <bits/stdc++.h>
using namespace std;

int n;
int stars[100001][3];
int diff[1002][1002];
int origin[1002][1002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stars[i][0] >> stars[i][1] >> stars[i][2];
    }
    for (int i = 0; i < n; i++) {
        int a = stars[i][0], b = stars[i][1], r = stars[i][2];
        int x = max(0, a - r + 500);
        int y = max(0, b - r + 500);
        int ex = min(1000, a + r + 500);
        int ey = min(1000, b + r + 500);
        diff[x][y]++;
        diff[x][ey + 1]--;
        diff[ex + 1][y]--;
        diff[ex + 1][ey + 1]++;
    }
    // ai,j = ai-1,j + ai,j+1 - ai-1,j-1 + diff i,j
    origin[0][0] = diff[0][0];
    for (int i = 1; i <= 1000; i++) {
        origin[0][i] = diff[0][i] + origin[0][i - 1];
        origin[i][0] = diff[i][0] + origin[i - 1][0];
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            origin[i][j] = diff[i][j] + origin[i - 1][j] + origin[i][j - 1] -
                           origin[i - 1][j - 1];
        }
    }
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << origin[x + 500][y + 500] << endl;
    }
    return 0;
}