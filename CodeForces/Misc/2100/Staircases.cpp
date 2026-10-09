//
// Created by JMKov on 7/27/2024.
//
#include <iostream>
using namespace std;

long long n, m, q;
bool explored[1002][1002];

long long query(long long i, long long j) {
    long long ret = 0;
    for (long long k = 0; k < 2; k++) {
        long long a = i;
        long long b = j;
        long long cnt1 = 0;
        while (a >= 0 && b >= 0) {
            if (cnt1 % 2 == k) a--;
            else b--;
            cnt1++;
            if (!(a >= 0 && b >= 0) || explored[a][b]) break;
        }
        a = i;
        b = j;
        long long cnt2 = 0;
        while (a < n && b < m) {
            if (cnt2 % 2 == k) b++;
            else a++;
            cnt2++;
            if (!(a < n && b < m) || explored[a][b]) break;
        }
        ret += cnt1 * cnt2;
    }
    return ret - 1;
}

int main() {
    cin >> n >> m >> q;
    long long ans = 0;
    long long cnt = 2;
    while (true) {
        long long a = cnt / 2;
        long long b = cnt - a;
        if (min(a, b) > max(n, m)) break;
        ans += (max(0ll, (n - a + 1)) * max(0ll, (m - b + 1)) + max(0ll, (n - b + 1)) * max(0ll, (m - a + 1))) / (1 + (a == 1 && b == 1));
        cnt++;
    }
    while (q--) {
        long long x, y;
        cin >> x >> y;
        x--; y--;
        explored[x][y] = !explored[x][y];
        long long amnt = query(x, y);
        ans += ((!explored[x][y]) ? 1 : -1) * amnt;
        cout << ans << endl;
    }
    return 0;
}