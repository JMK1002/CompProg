//
// Created by JMKov on 5/30/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long n, x, y;
string a, b;
vector<long long> inds;
long long dp[5002];

void clean() {
    inds.clear();
    for (long long i = 0; i < n; i++) dp[i] = 0;
}

void solve() {
    cin >> n >> x >> y >> a >> b;
    for (long long i = 0; i < n; i++) {
        if (a[i] != b[i]) inds.push_back(i);
    }
    if (inds.size() % 2 == 1) {
        cout << -1 << endl;
        clean();
        return;
    }
    if (x > y) {
        if (inds.size() == 2 && inds[1] - inds[0] == 1) {
            cout << min(2 * y, x) << endl;
        }
        else if (inds.size() == 2) {
            cout << y << endl;
        }
        else {
            cout << ((inds.size()) / 2 * y) << endl;
        }
        clean();
        return;
    }
    for (long long i = 1; i <= inds.size(); i++) {
        if (i & 1) {
            dp[i] = min(dp[i - 1], (i == 1) ? INT32_MAX : dp[i - 2] + (inds[i - 1] - inds[i - 2]) * x);
        }
        else {
            dp[i] = min(dp[i - 2] + (inds[i - 1] - inds[i - 2]) * x, dp[i - 1] + y);
        }
    }
//    for (long long i = 0; i <= inds.size(); i++) cout << dp[i] << " ";
//    cout << endl;
    cout << dp[inds.size()] << endl;
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
}