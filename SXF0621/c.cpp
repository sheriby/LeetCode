#include <bits/stdc++.h>
using namespace std;

int mat[102][102];
int mat2[102][102];
int m, n, k;

int liveCount(int x, int y) {
    int cnt = 0;
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++) {
            if (x == i && y == j)
                continue;
            if (mat[i][j] == 1)
                cnt++;
        }
    return cnt;
}

void round() {
    for (int i = 1; i <= m; i++) {
        mat[i][0] = mat[i][n];
        mat[i][n + 1] = mat[i][1];
    }
    for (int i = 1; i <= n; i++) {
        mat[0][i] = mat[m][i];
        mat[m + 1][i] = mat[1][i];
    }
    mat[0][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int cnt = liveCount(i, j);
            if (mat[i][j] == 1) {
                if (cnt == 2 || cnt == 3)
                    mat2[i][j] = 1;
                else
                    mat2[i][j] = 0;
            } else {
                if (cnt == 3)
                    mat2[i][j] = 1;
            }
        }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            mat[i][j] = mat2[i][j];
        }
}

int main() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++)
            mat[i][j] = str[j - 1] - '0';
    }

    for (int i = 0; i < k; i++)
        round();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[i][j];
        cout << endl;
    }

    return 0;
}