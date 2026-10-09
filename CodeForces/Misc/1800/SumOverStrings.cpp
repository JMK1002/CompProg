//
// Created by JMKov on 4/17/2024.
//
#include <iostream>
#include <set>

using namespace std;

void solve() {
    string s;
    long long n;
    cin >> n >> s;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i; j < n; j++) {
            for (int k = i; k <= j; k++) {
                if (s[k] == '1') {
                    ans++;
                    k += 2;
                }
            }
        }
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