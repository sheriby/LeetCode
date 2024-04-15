#include <bits/stdc++.h>
using namespace std;

int x = 0, y = 0;

char d[4] = {'W', 'A', 'S', 'D'};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void move(string str) {
    if (str.size() < 2 || str.size() > 3) return;
    int dir = -1;
    for (int i = 0; i < 4; ++i)
        if (str[0] == d[i]) dir = i;
    if (dir == -1) return;
    int num = 0;
    for (int i = 1; i < str.size(); ++i) {
        num *= 10;
        if (!isdigit(str[i])) return;
        num += str[i] - '0';
    }
    x += num * dx[dir];
    y += num * dy[dir];
}

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int start = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ';') {
            move(str.substr(start, i - start));
            start = i + 1;
        }
    }

    cout << x << "," << y << endl;

    return 0;
}