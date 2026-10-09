#include <iostream>
using namespace std;

int n;
long long arr[500005];
long long pre[500005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    long long ans = 9000000000000000;
    for (int i = 1; i <= n / 2; i++) {
        ans = min(ans, pre[i + n / 2] - pre[i - 1]);
    }
    cout << ans << " " << pre[n] - ans << endl;
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        pre[i] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}