//
// Created by JMKov on 7/15/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, ones;
string a, b;
long long m[1000005][4];
long long ans[1000005];

long long md(long long v) {
    if (v < 0) v += mod * 5000000000;
    return v % mod;
}

void mult(long long r, long long v) {
    for (long long i = 0; i < 4; i++) {
        m[r][i] *= v;
        m[r][i] = md(m[r][i]);
    }
}

void add(long long r1, long long r2) {
    for (long long i = 0; i < 2; i++) {
        m[r1][i] += m[r2][i + 1];
        m[r1][i] = md(m[r1][i]);
    }
    m[r1][3] += m[r2][3];
    m[r1][3] = md(m[r1][3]);
}

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    cin >> n >> a >> b;
    for (long long i = 0; i < n; i++) {
        ones += (a[i] - '0') ^ (b[i] - '0');
    }
    for (long long i = 0; i < n; i++) {
        m[i][0] = i * -1;
        m[i][1] = n;
        m[i][2] = (n - i) * -1;
        m[i][3] = n;
    }
    m[0][0] = 0;
    m[n - 1][2] = 0;

    for (long long i = 0; i < n - 1; i++) {
        mult(i, md(m[i + 1][0] * inv(m[i][1]) * -1));
        add(i + 1, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = md(md(m[i][3] - md(ans[i + 1] * m[i][2])) * inv(m[i][1]));
    }
    cout << ans[n - ones] << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) m[i][j] = 0;
        ans[i] = 0;
    }
    ones = 0;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}