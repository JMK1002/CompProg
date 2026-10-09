#include <iostream>
using namespace std;

bool arr[2][100005];
int dp[3][100005];
int pre[2][100005];

void solve() {
    long long n;
    cin >> n;
    string a[2];
    cin >> a[0] >> a[1];
    for (long long i = 4; i <= n + 3; i++) {
        arr[0][i] = (a[0][i - 4] == 'A');
        arr[1][i] = (a[1][i - 4] == 'A');
        pre[0][i] = pre[0][i - 1] + arr[0][i];
        pre[1][i] = pre[1][i - 1] + arr[1][i];
    }
    long long cnt = 0;
    for (long long i = 4; i <= n + 3; i++) {
        int tot = arr[0][i - 1] + arr[0][i - 2] + arr[1][i - 1] + arr[1][i - 2];
        int tl = (tot - arr[0][i - 2]) >= 2;
        int tr = (tot - arr[0][i - 1]) >= 2;
        int br = (tot - arr[1][i - 2]) >= 2;
        int bl = (tot - arr[1][i - 1]) >= 2;

        dp[0][i] = max(dp[0][i], dp[0][i - 1]);
        dp[1][i] = max(dp[1][i], dp[1][i - 1]);
        dp[2][i] = max(dp[2][i], dp[2][i - 1]);

        int k = (pre[0][i - 3] - pre[0][i] <= 2) +
             (pre[1][i - 3] - pre[1][i] <= 2);
        dp[0][i] = max(dp[0][i], dp[0][i - 3] + k);
        dp[1][i] = max(dp[1][i], dp[0][i - 2] + br);
        dp[2][i] = max(dp[2][i], dp[0][i - 2] + tr);

        if (i >= 7) {
            k = (pre[0][i - 2] - pre[0][i + 1] <= 2) +
                (pre[1][i - 3] - pre[1][i] <= 2);
            dp[0][i] = max(dp[0][i], dp[1][i - 1] + tl);
            dp[1][i] = max(dp[1][i], dp[1][i - 3] + k);

            k = (pre[0][i - 3] - pre[0][i] <= 2) +
                (pre[1][i - 2] - pre[1][i + 1] <= 2);
            dp[0][i] = max(dp[0][i], dp[2][i - 1] + bl);
            dp[2][i] = max(dp[2][i], dp[2][i - 3] + k);
        }
    }
    cout << dp[0][n + 3] << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}