#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n;
long long arr[200004];
long long diff[200004];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    diff[0] = arr[0];
    for (long long i = 1; i < n; i++) {
        diff[i] = arr[i] - arr[i - 1];
        if (diff[i] < 0 || diff[i] > 2 || arr[n - 1] != n || arr[i - 1] > i) {
            cout << 0 << endl;
            return;
        }
    }

    long long ans = 1;
    for (long long i = 0; i < n; i++) {
        if (diff[i] == 0) continue;
        else if (diff[i] == 1) {
            ans *= 2 * (i - arr[i] + 1) + 1;
        }
        else {
            ans *= (i - arr[i] + 2) * (i - arr[i] + 2);
        }
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}