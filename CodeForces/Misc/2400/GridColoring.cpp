#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    auto print = [&](int x, int y) {
        if (1 <= x && x <= n && 1 <= y && y <= m) {
            cout << x << " " << y << "\n";
        }
    };

    int cx = (n+1)/2;
    int cy = (m+1)/2;
    int layers = max(n, m)/2;
    print(cx, cy);
    for (int i = 1; i <= layers; i++) {
        for (int j = 0; j < 2*i-1; j++) {
            int sgn = (j & 1) ? 1 : -1;
            print(cx+sgn*(j+1)/2, cy+i);
            print(cx+sgn*(j+1)/2, cy-i);
        }
        for (int j = 0; j < 2*i-1; j++) {
            int sgn = (j & 1) ? 1 : -1;
            print(cx+i, cy+sgn*(j+1)/2);
            print(cx-i, cy+sgn*(j+1)/2);
        }
        print(cx-i, cy-i);
        print(cx-i, cy+i);
        print(cx+i, cy-i);
        print(cx+i, cy+i);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}
