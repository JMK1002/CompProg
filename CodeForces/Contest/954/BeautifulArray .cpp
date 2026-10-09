//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;
long long arr[100004];
long long pre[100004];
long long suff[100004];
map<long long, vector<long long>> mp;

void clean() {
    for (long long i = 0; i <= n; i++) {
        pre[i] = 0;
        suff[i] = 0;
        arr[i] = 0;
    }
    mp.clear();
}

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i] % k].push_back(arr[i]);
    }
    long long ans = 0;
    long long cnt = 0;
    for (pair<long long, vector<long long>> p : mp) {
        vector<long long> st = p.second;
        sort(st.begin(), st.end());
        if (st.size() % 2 == 1 && (n % 2 == 0 || cnt > 0)) {
            cout << -1 << endl;
            clean();
            return;
        }
        else if (st.size() % 2 == 1 && cnt == 0) { // odd length string
            cnt++;
            pre[0] = 0;
            suff[st.size() / 2] = 0;
            for (long long j = 1; j <= st.size() / 2; j++) {
                pre[j] = pre[j - 1] + abs(st[(j - 1) * 2] - st[(j - 1) * 2 + 1]) / k;
            }
            for (long long j = st.size() / 2 - 1; j >= 0; j--) {
                suff[j] = suff[j + 1] + abs(st[(j) * 2 + 1] - st[(j) * 2 + 2]) / k;
            }
            long long mn = 200000000000000;
            for (long long i = 0; i <= st.size() / 2; i++) mn = min(mn, suff[i] + pre[i]);
            ans += mn;
            continue;
        }

        for (long long j = 0; j < st.size() / 2; j++) {
            ans += abs(st[j * 2] - st[j * 2 + 1]) / k;
        }
    }
    cout << ans << endl;
    clean();
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