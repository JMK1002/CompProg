//
// Created by JMKov on 8/3/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const long long bts = 63;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long cnt[bts];
        long long sum = 0;
        for (long long & i : cnt) i = 0;
        for (long long i = 0; i < m; i++) {
            long long v;
            cin >> v;
            sum += v;
            v = (long long) log2(v);
            cnt[v]++;
        }
        if (sum < n) {
            cout << -1 << endl;
            continue;
        }
        vector<long long> s;
        long long asdf = 1;
        long long cntb = 0;
        while (n && cntb < bts) {
            if (n & asdf) {
                s.push_back(cntb);
            }
            asdf <<= 1;
            cntb++;
        }
        long long ans = 0;
        for (long long i : s) {
            for (long long j = 0; j < i; j++) {
                cnt[j + 1] += (cnt[j] >> 1);
                cnt[j] &= 1;
            }
            for (long long j = 0; j < bts - i; j++) {
                if (cnt[i + j] != 0) {
                    ans += j;
                    cnt[i + j]--;
                    break;
                }
                else {
                    cnt[i + j]++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}