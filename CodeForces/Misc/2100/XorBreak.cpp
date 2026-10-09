//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
#include <vector>
using namespace std;

long long n, m;

long long highestBit(long long k) {
    long long ans = 0;
    for (long long i = 0; ((long long) 1 << i) <= k; i++) {
        ans = i;
    }
    return ans;
}

long long amntOfOnes(long long k, long long ind) {
    long long ans = 0;
    for (long long i = ind; i >= 0; i--) {
        if (k & ((long long) 1 << i)) ans++;
        else break;
    }
    return ans;
}

void solve() {
    cin >> n >> m;
//    n = ((long long) 1 << 59) + ((long long) 1 << 58);
//    m = 1;

    if ((n ^ m) < n && (n ^ m) > 0) {
        cout << 1 << endl;
        cout << n << " " << m << endl;
        return;
    }

    long long highest = highestBit(n);
    long long secondHighest = 0;
    vector<long long> ans;
    ans.push_back(n);
    for (long long i = highest - 1; i >= 0; i--) {
        if (((long long) 1 << i) & n) {
            secondHighest = i;
            break;
        }
    }
    if ((n ^ m) & ((long long) 1 << highest)) {
        n ^= ((long long) 1 << highest);
        for (long long i = 0; i < secondHighest; i++) {
            if ((n ^ m) & ((long long) 1 << i)) n ^= ((long long) 1 << i);
        }
    }
    else {
        n ^= secondHighest;
        for (long long i = 0; i < secondHighest; i++) {
            if ((n ^ m) & ((long long) 1 << i)) n ^= ((long long) 1 << i);
        }
    }
    ans.push_back(n);
    if ((n ^ m) < n && (n ^ m) > 0 && m < n && m > 0) {
        ans.push_back(m);
        cout << ans.size() - 1 << endl;
        for (long long i : ans) cout << i << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//481885160128643073 45035996273704960
// 110
// 101