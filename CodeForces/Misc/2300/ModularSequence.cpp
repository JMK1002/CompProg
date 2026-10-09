//
// Created by JMKov on 8/13/2024.
//
#include <iostream>
using namespace std;

long long n, x, y, s, ns, nx;
pair<long long, long long> dp[200005];

void printBlc(long long a) {
    for (long long i = 0; i < a; i++) cout << (x % y) + i * y << " ";
}

void solve() {
    cin >> n >> x >> y >> s;
    nx = x - (x % y);
    nx /= y;
    ns = s - (x % y) * n;
    if (ns % y != 0 || ns < 0) {
        cout << "NO" << endl;
        return;
    }
    ns /= y;
    long long sum = nx;
    long long prev = nx;
    for (long long i = 1; i <= n; i++) {
        if (ns - sum < 0) break;
        if (dp[ns - sum].first <= n - i) {
            cout << "YES" << endl;
            for (long long j = 0; j < i; j++) cout << x + j * y << " ";
            for (long long j = 0; j < n - i - dp[ns - sum].first; j++) cout << (x % y) << " ";
            long long p = ns - sum;
            while (p != 0) {
                printBlc(dp[p].second + 1);
                p -= dp[p].second * (dp[p].second + 1) / 2;
            }
            cout << endl;
            return;
        }
        prev = prev + 1;
        sum += prev;
    }
    cout << "NO" << endl;
}

int main() {
    for (long long i = 1; i < 200005; i++) {
        dp[i] = {1000000000, -1};
        for (long long j = 1; i - j * (j + 1) / 2 >= 0; j++) {
            if (dp[i - j * (j + 1) / 2].first + j + 1 < dp[i].first) {
                dp[i] = {dp[i - j * (j + 1) / 2].first + j + 1, j};
            }
        }
    }
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}