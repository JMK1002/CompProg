#include <iostream>
using namespace std;

long long n, k, p;
long long dp[404][404][404]; // ! dp[i][j][k] is n, second to last, last elements
long long pre[404][404][404];

void solve() {
    cin >> n >> k >> p;
    for (long long i = 3; i <= n + 2; i++) {
        for (long long l = 0; l <= k; l++) {
            for (long long j = k; j >= 0; j--) {
                dp[i][j][l] = pre[i - 1][max(0ll, j - l)][j];
                dp[i][j][l] %= p;
                pre[i][j][l] = pre[i][j + 1][l] + dp[i][j][l];
                pre[i][j][l] %= p;
                // cout << pre[i][j][l] << " ";
            }
            // cout << endl;
        }
    }
    cout << dp[n + 2][0][0] % p << endl;
    for (int i = 3; i <= n + 2; i++) for (int l = 0; l <= k; l++) for (int j = k; j >= 0; j--) pre[i][j][l] = 0;
}

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i <= 400; i++) {
        for (long long j = i; j <= 400; j++) {
            dp[2][i][j] = 1;
        }
    }
    for (long long i = 0; i <= 400; i++) {
        for (long long j = 400; j >= 0; j--) {
            pre[2][j][i] = pre[2][j + 1][i] + dp[2][j][i];
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}