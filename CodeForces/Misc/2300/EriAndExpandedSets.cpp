#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int t[2000000];
int arr[400005];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = __gcd(t[v*2], t[v*2+1]);
    }
}

int q(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(q(v*2, tl, tm, l, min(r, tm)), q(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    cin >> n;
    int ans = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        // if (i != 1) {
        //     bool asdf = arr[i] == arr[i - 1];
        //     if (asdf) cnt++;
        //     else {
        //         ans += cnt * (cnt + 1) / 2;
        //         cnt = 1;
        //     }
        // }
    }
    // ans += cnt * (cnt + 1) / 2;
    for (int i = 2; i <= n; i++) arr[i - 1] = abs(arr[i] - arr[i - 1]);
    arr[0] = 1;
    build(1, 0, n - 1);
    for (int i = 1; i < n; i++) {
        int low = 0;
        int high = i + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            int x = q(1, 0, n - 1, mid, i);
            while (x && x % 2 == 0) x /= 2;
            if (x == 1 || x == 0) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        ans += low;
    }

    cout << ans + n << endl;
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i <= 4 * n; i++) t[i] = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//6
//1 3 6 10 15 21
//0 1 1 4  4  