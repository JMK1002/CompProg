#include <iostream>
#include <vector>
using namespace std;

long long n, m, v;
long long arr[200005];
long long pre[200005];
vector<long long> beg;
vector<long long> suff;

void solve() {
    cin >> n >> m >> v;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (long long i = 1; i <= n; i++) pre[i] = arr[i] + pre[i - 1];
    beg.push_back(0);
    long long last = 0;
    for (long long i = 1; i <= n; i++) {
        if (pre[i] - pre[last] >= v) {
            beg.push_back(i);
            last = i;
        }
    }
    suff.push_back(n + 1);
    last = n;
    for (long long i = n; i >= 1; i--) {
        if (pre[last] - pre[i - 1] >= v) {
            suff.push_back(i);
            last = i - 1;
        }
    }
    // for (long long i : beg) cout << i << " ";
    // cout << endl;
    // for (long long i : suff) cout << i << " ";
    // cout << endl;
    long long ans = -1;
    if (beg.size() < m + 1) {
        cout << -1 << endl;
        beg.clear();
        suff.clear();
        return;
    }
    for (long long i = 0; i <= m; i++) {
        ans = max(ans, pre[suff[i] - 1] - pre[beg[m - i]]);
    }
    cout << ans << endl;
    beg.clear();
    suff.clear();
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