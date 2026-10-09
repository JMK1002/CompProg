//
// Created by JMKov on 7/10/2024.
//
#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007;

long long n, k;
long long arr[103];
vector<long long> cols[103];
long long colInd[103];
long long ch[103]; // choose k - 2
long long dp[103][103]; // i is prefix, j is amount of blocks
long long preDp[103][103]; // i is prefix, j is amount of blocks

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void clean() {
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        cols[i].clear();
        colInd[i] = 0;
        for (long long j = 0; j <= n; j++) {
            dp[i][j] = 0;
            preDp[i][j] = 0;
        }
    }
    for (long long i = 0; i < 103; i++) {
        ch[i] = 0;
    }
}

void solve() {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        cols[arr[i]].push_back(i);
    }
    if (k == 1) {
        cout << 1 << endl;
        clean();
        return;
    }

    ch[k - 2] = 1;
    for (long long i = k - 1; i < 102; i++) {
        ch[i] = ch[i - 1] * inv(i - (k - 2)) % mod * (i) % mod;
    }
    dp[0][0] = 1;
    preDp[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
        for (long long j = colInd[arr[i]] - k + 1; j >= 0; j--) {
            for (long long l = 1; l <= n; l++) {
                dp[i][l] += preDp[cols[arr[i]][j] - 1][l - 1] * ch[colInd[arr[i]] - j - 1];
                dp[i][l] %= mod;
            }
        }
        for (long long l = 0; l <= n; l++) {
            preDp[i][l] = preDp[i - 1][l] + dp[i][l];
            preDp[i][l] %= mod;
        }
        colInd[arr[i]]++;
    }
    long long ans = 1;
    for (long long i = 1; i < n; i++) {
        if (preDp[n][i] == 0) break;
        ans = preDp[n][i];
    }
    cout << ans << endl;
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}