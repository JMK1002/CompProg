//
// Created by JMKov on 6/19/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool adj[1002][1002]; // TODO: adj[i][i] MUST NEVER BE CONSIDERED

void clean() {
    return;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            adj[i][j] = s[j] == 'a';
        }
    }

    if (m % 2 == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < (m + 1) / 2; i++) {
            cout << "1 2 ";
        }
        cout << endl;
        clean();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] == adj[j][i]) {
                cout << "YES" << endl;
                for (int k = 0; k < m / 2; k++) {
                    cout << i + 1 << " " << j + 1 << " ";
                }
                cout << i + 1 << endl;
                clean();
                return;
            }
        }
    }

    if (n == 2) {
        cout << "NO" << endl;
        clean();
        return;
    }
    cout << "YES" << endl;
    vector<int> ord;
    for (int i = 0; i < 3; i++) {
        if (adj[i][(i + 1) % 3] == adj[(i + 1) % 3][(i + 2) % 3]) {
            ord = {i, (i + 1) % 3, (i + 2) % 3, (i + 1) % 3};
        }
    }
    for (int i = (m % 4 == 0); i <= m + (m % 4 == 0); i++) {
        cout << ord[i % 4] + 1 << " ";
    }
    cout << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 4 8
// *aaa
// b*aa
// bb*a
// bbb*