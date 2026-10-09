//
// Created by JMKov on 7/7/2024.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

long long n;
vector<long long> a;
vector<long long> b;
vector<long long> v;

long long inv(long long l, long long r) {
    if (l == r) {
        return 0;
    }
    long long mid = (l + r) / 2;
    long long x = inv(l, mid);
    long long y = inv(mid + 1, r);
    v.clear();
    for (long long i = l; i <= mid; i++) {
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (long long i = mid + 1; i <= r; i++) {
        res += v.end() - lower_bound(v.begin(), v.end(), a[i]);
    }
    return x + y + res;
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        b.push_back(x);
    }
    long long x = inv(0, n - 1);
    swap(a, b);
    long long y = inv(0, n - 1);
//    cout << x << " " << y << endl;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (long long i = 0; i < n; i++) if (a[i] != b[i]) {
        cout << "NO" << endl;
        return;
    }
    if ((x - y + 1000000000) % 2 == 0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
        a.clear();
        b.clear();
        v.clear();
    }
    return 0;
}