#include <bits/stdc++.h>
using namespace std;

int attack[2][5];
int blood[2][5];

int main() {
    for (int i = 0; i < 5; i++)
        cin >> attack[0][i];
    for (int i = 0; i < 5; i++)
        cin >> blood[0][i];
    for (int i = 0; i < 5; i++)
        cin >> attack[1][i];
    for (int i = 0; i < 5; i++)
        cin >> blood[1][i];

    int i = 0, j = 0, op = 0;
    while (i < 5 && j < 5) {
        if (op == 0) {
            blood[1][j] -= attack[0][i];
            if (blood[1][j] <= 0)
                ++j;
            op = 1;
        } else {
            blood[0][i] -= attack[1][j];
            if (blood[0][i] <= 0)
                ++i;
            op = 0;
        }
    }
    if (i == 5) {
        cout << "lose" << endl;
        cout << 5 - j << endl;
    } else {
        cout << "win" << endl;
        cout << 5 - i << endl;
    }

    return 0;
}