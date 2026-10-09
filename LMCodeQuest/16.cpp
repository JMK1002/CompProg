//
// Created by JMKov on 2/24/2024.
//
#include <iostream>
using namespace std;

pair<pair<int, int>, int> read() {
    char c;
    cin >> c;
    pair<pair<int, int>, int> ret;
    cin >> ret.first.first >> c >> ret.first.second >> c >> ret.second >> c;
    return ret;
}

void print(pair<pair<int, int>, int> p) {
    cout << "(" << p.first.first << "," << p.first.second << "," << p.second << ")";
}

void solve() {
    pair<pair<int, int>, int> h = read();
    int n, m;
    cin >> n >> m;
    bool harr[m][n];
    int p[m][n];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) p[i][j] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = max(p[i][j], 0);
            int v;
            cin >> v;
            harr[i][j] = (v == 1);
            if (!harr[i][j]) continue;
            for (int x = max(0, i - 1); x <= min(m - 1, i + 1); x++) {
                for (int y = max(0, j - 1); y <= min(n - 1, j + 1); y++) {
                    p[x][y] = max(p[x][y], 1);
                }
            }
            p[i][j] = max(p[i][j], 2);
        }
    }
    pair<pair<int, int>, int> carr[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            carr[i][j] = read();
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] == 0) continue;
            if (p[i][j] == 1) {
                carr[i][j] = h;
            }
            if (p[i][j] == 2) {
                carr[i][j].first.first += h.first.first;
                carr[i][j].first.second += h.first.second;
                carr[i][j].second += h.second;
                carr[i][j].first.first += (carr[i][j].first.first % 2);
                carr[i][j].first.second += (carr[i][j].first.second % 2);
                carr[i][j].second += (carr[i][j].second % 2);
                carr[i][j].first.first /= 2;
                carr[i][j].first.second /= 2;
                carr[i][j].second /= 2;

            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            print(carr[i][j]);
            if (j != n - 1) cout << " ";
        }
        cout << endl;
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