#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
queue<int> q[26];
string a, b;

void clean() {
    for (int i = 0; i < 26; i++) while (!q[i].empty()) q[i].pop();
}

void solve() {
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) q[a[i] - 'a'].push(i);
    for (int i = 0; i < m; i++) {
        char c = b[i] - 'a';
        if (q[c].empty()) {
            cout << "NO" << endl;
            clean();
            return;
        }
        int ind = q[c].front();
        q[c].pop();
        for (int j = c - 1; j >= 0; j--) {
            while (!q[j].empty() && q[j].front() < ind) q[j].pop();
        }
    }
    cout << "YES" << endl;
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
