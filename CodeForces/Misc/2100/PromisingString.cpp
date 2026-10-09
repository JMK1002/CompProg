//
// Created by JMKov on 7/22/2024.
//
#include <iostream>
using namespace std;

long long n;
long long cnt[3];
long long amnt[400005];

void solve() {
    cin >> n;
    long long val = n;
    amnt[n] = 1;
    cnt[n % 3] = 1;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cnt[val % 3] -= amnt[val];
            val++;
            ans += cnt[val % 3];
            amnt[val]++;
            cnt[val % 3]++;
        }
        else {
            val--;
            amnt[val]++;
            cnt[val % 3] += amnt[val];
            ans += cnt[val % 3] - 1; // - 1 for the case where substring is len 0
        }
//        cout << ans << endl;
    }
    cout << ans << endl;
    for (long long i = 0; i < 2 * n + 2; i++) amnt[i] = 0;
    for (long long i = 0; i < 3; i++) cnt[i] = 0;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}