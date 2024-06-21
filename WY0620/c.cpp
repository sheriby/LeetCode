#include <bits/stdc++.h>
using namespace std;

int n;
int stars[100001][3];
int influenceCot(int x, int y) {
    int cot = 0;
    for (int i = 0; i < n; i++) {
        if (max(abs(stars[i][0] - x), abs(stars[i][1] - y)) <= stars[i][2])
            cot++;
    }
    return cot;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stars[i][0] >> stars[i][1] >> stars[i][2];
    }
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << influenceCot(x, y) << endl;
    }
    return 0;
}