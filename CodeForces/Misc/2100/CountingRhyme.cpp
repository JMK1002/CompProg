//
// Created by JMKov on 7/4/2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const long long MAXN = 1000006;

long long n;
long long arr[MAXN];
vector<long long> primes;
long long fact[MAXN];
long long cnt[MAXN];
bool add[MAXN];

void solve() {
    cin >> n;
    set<long long> vals;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        vals.insert(arr[i]);
        cnt[arr[i]]++;
    }
    for (long long i = 1; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) cnt[i] += cnt[j];
    }
    for (long long i = 0; i <= n; i++) cnt[i] = (cnt[i] * (cnt[i] - 1) / 2);
    for (long long i = n; i >= 1; i--) {
        for (long long j = i * 2; j <= n; j += i) {
            cnt[i] -= cnt[j];
        }
    }
    for (long long i : vals) {
        for (long long j = i; j <= n; j += i) add[j] = true;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans += cnt[i] * add[i];
    }
    cout << n * (n - 1) / 2 - ans << endl;

    for (long long i = 0; i <= n + 1; i++) {
        cnt[i] = 0;
        add[i] = false;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}