//
// Created by JMKov on 5/29/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    long long ans = 0;
    vector<long long> a(n);
    vector<long long> b(m);
    if (k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < m; i++) cin >> b[i];
    for (long long i = 0; i <= min(n, k); i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i] + ta);
        if (distance(it, b.end()) - k + i <= 0) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, *(lower_bound(b.begin(), b.end(), a[i] + ta) + k - i) + tb);
    }
    cout << ans << endl;
    return 0;
}

//4 5 1 1 2
//a: 1 3 5 7
//b: 1 2 3 9 10

// *(lower_bound(b.begin(), b.end(), a[i] + ta) + k - i) + tb