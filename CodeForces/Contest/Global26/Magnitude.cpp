//
// Created by JMKov on 6/9/2024.
//
#include <iostream>
using namespace std;

long long mod = 998244353;

long long arr[200004];
long long mx[200004];
long long pw[200004];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    long long s = 0;
    long long cnt = 0;
    long long asdf = 1;
    long long ans = 1;
    bool diff = false;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        s += arr[i];

        if (mx[i - 1] + arr[i] >= 0) {
            ans *= 2;
            diff = true;
        }

        if (diff && s * -1 == abs(mx[i - 1] + arr[i])) {
            ans += binpow(2, i - cnt - 1, mod);
            mx[i] = abs(mx[i - 1] + arr[i]);
            diff = false;
        }
        else if (abs(s) > abs(mx[i - 1] + arr[i])) {
            mx[i] = abs(s);
            ans = 0;
        }
        else {
            mx[i] = abs(mx[i - 1] + arr[i]);
        }

        cnt += s <= 0;
        cout << ans << " ";
    }
    cout << endl;
//    cout << ans << endl;
    for (long long i = 0; i <= n; i++) {
        mx[i] = 0;
        arr[i] = 0;
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}