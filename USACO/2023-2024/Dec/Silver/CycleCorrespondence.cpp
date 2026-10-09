//
// Created by JMKov on 12/16/2023.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;
long long aInd[500005];
long long bInd[500005];
long long cnt[500005];
long long a[500005];
long long b[500005];
long long diff[500005];

int solve() {
    for (long long i = 0; i < n; i++) {
        if (aInd[i] == -1 || bInd[i] == -1) continue;
        if ((aInd[i] - bInd[i]) < 0) {
            diff[(aInd[i] - bInd[i]) + k]++;
        }
        else {
            diff[(aInd[i] - bInd[i])]++;
        }
    }
    long long mx = 0;
    for (long long i : diff) mx = max(mx, i);
//    cout << mx << endl;

    long long zCnt = 0;
    for (long long i = 0; i < n; i++) zCnt += (cnt[i] == 0);
    return mx + zCnt;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        aInd[i] = -1;
        bInd[i] = -1;
        cnt[i] = 0;
    }

    for (long long i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
        aInd[a[i]] = i;
    }

    for (long long i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
        cnt[b[i]]++;
        bInd[b[i]] = i;
    }
    int s1 = solve();
    reverse(b, b + k);

    for (long long i = 0; i < n; i++) {
        bInd[i] = -1;
        cnt[i] = 0;
        diff[i] = 0;
    }
    for (long long i = 0; i < k; i++) {
        cnt[b[i]]++;
        bInd[b[i]] = i;
        cnt[a[i]]++;
    }
    int s2 = solve();
    cout << max(s1, s2) << endl;
}