//
// Created by JMKov on 7/7/2024.
//
#include <iostream>
using namespace std;

int n, m;
int a[502][502];
int b[502][502];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) b[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == b[i][j]) continue;
            int tl = (b[i][j] - a[i][j] + 3) % 3;
            int tr = (tl == 1) ? 2 : 1;
            a[i][j] += tl;
            a[i + 1][j + 1] += tl;
            a[i + 1][j] += tr;
            a[i][j + 1] += tr;
            a[i][j] %= 3;
            a[i + 1][j + 1] %= 3;
            a[i + 1][j] %= 3;
            a[i][j + 1] %= 3;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] != b[i][j]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}