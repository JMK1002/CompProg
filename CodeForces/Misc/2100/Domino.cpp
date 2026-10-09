//
// Created by JMKov on 7/29/2024.
//
#include <iostream>
using namespace std;

int n, m, h, v;
char ans[102][102];

void fill(int xo, int yo) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            int x = i * 2 + xo;
            int y = j * 2 + yo;
            char c1 = ((i + j) % 2) ? 'a' : 'c';
            char c2 = ((i + j) % 2) ? 'b' : 'd';

            if (h > 0) {
                ans[x][y] = c1;
                ans[x + 1][y] = c2;
                ans[x][y + 1] = c1;
                ans[x + 1][y + 1] = c2;
                h -= 2;
            }
            else {
                ans[x][y] = c1;
                ans[x + 1][y] = c1;
                ans[x][y + 1] = c2;
                ans[x + 1][y + 1] = c2;
                v -= 2;
            }
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j];
        cout << endl;
    }
}

void solve() {
    cin >> n >> m >> h;
    v = n * m / 2 - h;
    if (n % 2 == 0 && m % 2 == 0) {
        if (h % 2 == 0) {
            cout << "YES" << endl;
            fill(0, 0);
            print();
        }
        else cout << "NO" << endl;
    }
    else if (n % 2 == 1) {
        h -= m / 2;
        if (h >= 0 && h % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < m / 2; i++) {
                char c = (i % 2) ? 'z' : 'w';
                ans[0][i * 2] = c;
                ans[0][i * 2 + 1] = c;
            }
            fill(1, 0);
            print();
        }
        else cout << "NO" << endl;
    }
    else {
        v -= n / 2;
        if (v >= 0 && v % 2 == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n / 2; i++) {
                char c = (i % 2) ? 'z' : 'w';
                ans[i * 2][0] = c;
                ans[i * 2 + 1][0] = c;
            }
            fill(0, 1);
            print();
        }
        else cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}