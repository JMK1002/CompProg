#include <iostream>
using namespace std;

long long n;
long long arr[200005];
long long ans[200005];
long long pre[400015];

void add(long long i, long long x) {
    arr[i] += x;
    arr[(i + 1) % n] += x;
    pre[(i + 2)] -= x;
    pre[i + 2 + (n / 2) * 2] += x;
}

void addEdges(long long i, long long x) {
    arr[i] -= x;
    arr[n - i - 1] -= x;
    pre[i + 1] -= x;
    pre[n - i] += x;
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i < n / 2; i++) add(i, arr[n - i - 1] - arr[i]);
    for (long long i = n / 2 - 1; i >= 0; i--) addEdges(i, arr[i + 1] - arr[i]);

    long long r = 0;
    for (long long i = 0; i < 2 * n; i += 2) {
        r += pre[i];
        ans[i % n] += r;
    }
    r = 0;
    for (long long i = 1; i < 2 * n; i += 2) {
        r += pre[i];
        ans[i % n] += r;
    }

    long long mn = 1000000000000000000;
    for (long long i = 0; i < n; i++) mn = min(mn, ans[i]);
    for (long long i = 0; i < n; i++) cout << ans[i] - mn << " ";
    cout << endl;
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        ans[i] = 0;
        pre[i] = 0;
        pre[i + n] = 0;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}