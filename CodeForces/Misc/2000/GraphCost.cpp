//
// Created by JMKov on 5/30/2024.
//
#include <iostream>
using namespace std;

long long n, m;
long long phi[1000004];
long long cnt[1000004];
long long top = 0;

void phi_1_to_n() {
    for (long long i = 0; i <= n; i++)
        phi[i] = i;

    for (long long i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (long long j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

long long rec(long long v) {
    if (v == 0) return 0;

    if (cnt[top] == 0) {
        top--;
    }

    long long ind = min(top, v + 1);
    if (v > (ind - 1) * cnt[ind]) {
        long long asdf = cnt[ind];
        cnt[ind] = 0;
        return asdf + rec(v - (ind - 1) * asdf);
    }
    else {
        return v / (ind - 1) + rec(v % (ind - 1));
    }
}

void solve() {
    cin >> n >> m;
    phi_1_to_n();

    phi[1] = 0;
    long long sum = 0;
    for (long long i = 2; i <= n; i++) {
        long long amnt = 0;
        for (long long j = 1; i * j <= n; j++) {
            amnt += phi[j];
        }
        cnt[i] = amnt / (i - 1);
        sum += cnt[i] * (i - 1);
        if (cnt[i] == 0) {
            top = i - 1;
            break;
        }
    }
    if (sum < m) cout << -1 << endl;
    else cout << m + rec(m) << endl;

    for (long long i = 0; i <= n; i++) {
        cnt[i] = 0;
        phi[i] = 0;
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