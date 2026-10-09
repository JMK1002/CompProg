#include <iostream>
#include <set>
using namespace std;

int n, a, b;
string s;

void solve() {
    cin >> n >> a >> b;
    cin >> s;
    pair<int, int> p = {0, 0};
    for (int i = 0; i < 1000; i++) {
        for (char c : s) {
            if (c == 'N') p.second += 1;
            else if (c == 'S') p.second -= 1;
            else if (c == 'E') p.first += 1;
            else if (c == 'W') p.first -= 1;
            if (p == make_pair(a, b)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}