//
// Created by JMKov on 11/18/2023.
//
#include <iostream>
using namespace std;

int main() {
    cin.tie();
    istream::sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long s[n];
        long long e[n];
        for (long long i = 0; i < n; i++) cin >> s[i];
        for (long long i = 0; i < n; i++) cin >> e[i];
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans = max(ans, (e[i] - s[i] + m) % m);
        }
        cout << ans << endl;
    }
    return 0;
}