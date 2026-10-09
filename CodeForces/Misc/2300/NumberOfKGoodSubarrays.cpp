//
// Created by JMKov on 8/1/2024.
//
#include <iostream>
using namespace std;

const long long mod = 1000000007;

pair<long long, pair<long long, long long>> pre[61][61]; // answer for n = 2^i, k = j;

pair<long long, pair<long long, long long>> merge(pair<long long, pair<long long, long long>> a, pair<long long, pair<long long, long long>> b) {
    long long i = a.second.second % mod;
    long long j = b.second.first % mod;
    long long x = a.first + b.first - (i - 1) * i / 2 - (j - 1) * j / 2 + (i + j - 1) * (i + j) / 2;
    x %= mod;
    x += mod;
    x %= mod;
    long long y = (a.second.first == a.second.second) ? a.second.first + b.second.first : a.second.first;
    long long z = (b.second.first == b.second.second) ? b.second.second + a.second.second : b.second.second;
    return {x, {y, z}};
}

pair<long long, pair<long long, long long>> solve(long long n, long long k) {
    if (k < 0 || n <= 0) return {0, {0, 0}};
    long long cnt = 0;
    while ((1ll << (cnt + 1)) <= n) cnt++;
    auto p = merge(pre[cnt][k], solve(n - (1ll << cnt), k - 1));
    return p;
}

int main() {
    for (long long i = 0; i < 61; i++) pre[0][i] = {1, {1, 1}};
    for (long long i = 1; i < 61; i++) {
        pre[i][0] = {1, {1, 0}};
        for (long long j = 1; j < 61; j++) {
            pre[i][j] = merge(pre[i - 1][j], pre[i - 1][j - 1]);
        }
    }
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k).first << endl;
    }
    return 0;
}