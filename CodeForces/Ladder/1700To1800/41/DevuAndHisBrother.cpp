#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = (int) 1e5 + 100;

int n, m;
LL a[N], b[N];

LL f(LL k) {
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < k) {
            ans += (k - a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] > k) {
            ans += (b[i] - k);
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    LL ans = (LL) 1e18;
    int pos = 1;
    LL lo = 1, hi = (LL) 1e9;
    for (int it = 0; it < 100; it++) {
        assert(lo <= hi);
        LL mid1 = lo + (hi - lo) / 3;
        LL mid2 = hi - (hi - lo) / 3;
        assert(mid1 >= lo && mid1 <= hi);
        assert(mid2 >= lo && mid2 <= hi);
        if (f(mid1) < ans) {
            ans = f(mid1);
            pos = mid1;
        }
        if (f(mid2) < ans) {
            ans = f(mid2);
            pos = mid2;
        }
        //cout << mid1 << " " << mid2 << " " << f(mid1) << " " << f(mid2) << endl;
        if (f(mid1) >= f(mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }
    cout << ans << endl;
    //cout << pos << endl;
    return 0;
}