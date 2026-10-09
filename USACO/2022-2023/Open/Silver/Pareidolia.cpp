//
// Created by JMKov on 12/28/2023.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> chars[4]; // TODO 0 = b, 1 = e, 2 = s, 3 = i
long long dp[300005];
const long long INF = INT64_MAX;

long long end(long long start, long long len) {
    long long pos = start;
    if (pos == INF) return INF;
    long long inds[6]{1, 2, 2, 3, 1, 0};
    for (long long j = 0; j < len; j++) {
        pos = *(upper_bound(chars[inds[j]].begin(), chars[inds[j]].end(), pos));
        if (pos == INF) return INF;
    }
    return pos;
}

long long start(long long ind, long long len) {
    long long pos = ind;
    if (pos == -1) return -1;
    long long inds[6]{3, 2, 2, 1, 0, 1};
    for (long long j = 0; j < len; j++) {
        pos = *(--lower_bound(chars[inds[j]].begin(), chars[inds[j]].end(), pos));
        if (pos == -1) return -1;
    }
    return pos;
}

int main() {
    string s;
    cin >> s;
    long long n = s.size();
//    for (long long i = 0; i < 300000 / 6; i++) s += "bessie";
    long long ans = 0;
    for (long long i = 0; i < 4; i++) chars[i].push_back(-1);
    for (long long i = 0; i < n; i++) {
        if (s[i] == 'b') chars[0].push_back(i);
        else if (s[i] == 'e') chars[1].push_back(i);
        else if (s[i] == 's') chars[2].push_back(i);
        else if (s[i] == 'i') chars[3].push_back(i);
    }
    for (long long i = 0; i < 4; i++) chars[i].push_back(INF);
    long long last = -1;
    for (long long i = 0; i < n; i++) {
        if (s[i] == 'e' && start(i, 5) != last) {
            last = start(i, 5);
            long long ind = start(i, 6);
            long long added = (ind == -1) ? 0 : dp[ind];
            dp[i] = last + 1 + added;
        }
    }
    long long cnt = 0;
    for (long long i = 1; i < n; i++) {
        cnt = max(dp[i], cnt);
        ans += cnt;
    }
//    for (long long i = 0; i < n; i++) cout << dp[i] << " ";
//    cout << endl;
    cout << ans << endl;
//    ans = 0;
//    for (long long i = 0; i < n; i++) {
//        for (long long j = i + 1; j < n; j++) {
//            long long cnt = 0;
//            long long pos = i;
//            while (pos <= j) {
//                cnt++;
//                pos = end(pos, 6);
//            }
//        }
//        ans += cnt;
//    }
//    cout << ans << endl;
    return 0;
}
//749970000350000
//0 0 0 0 0 0 0 1 2 3 7