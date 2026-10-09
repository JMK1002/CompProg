//
// Created by JMKov on 8/5/2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long long mod = 8494983825901921;

long long n, m;
long long pw[300005];
vector<bool> arr[300005];
map<long long, long long> mp;

void clean() {
    mp.clear();
    for (long long i = 0; i < n; i++) arr[i].clear();
}

void solve() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (long long j = 0; j < m; j++) arr[i].push_back(s[j] - '0');
    }
    for (long long i = 0; i < m; i++) {
        long long hsh = 0;
        for (long long j = n - 1; j >= 0; j--) {
            hsh *= 2;
            hsh += arr[j][i];
            hsh %= mod;
        }
        long long v = hsh;
        for (long long j = 0; j < n; j++) {
            if (arr[j][i]) {
                hsh -= pw[j];
                hsh += mod;
                hsh %= mod;
            }
            else {
                hsh += pw[j];
                hsh %= mod;
            }
            mp[hsh]++;
            hsh = v;
        }
    }
    pair<long long, long long> ans = {0,0};
    for (pair<long long, long long> p : mp) {
        ans = max(ans, {p.second, p.first});
    }
    string strAns;
    for (long long i = 0; i < m; i++) {
        string s;
        long long hsh = 0;
        for (long long j = n - 1; j >= 0; j--) {
            s += (char) (arr[j][i] + '0');
            hsh *= 2;
            hsh += arr[j][i];
            hsh %= mod;
        }
        long long v = hsh;
        for (long long j = 0; j < n; j++) {
            if (arr[j][i]) {
                hsh -= pw[j];
                hsh += mod;
                hsh %= mod;
            }
            else {
                hsh += pw[j];
                hsh %= mod;
            }
            if (hsh == ans.second) {
                s[n - j - 1] = '1' - s[n - j - 1] + '0';
                strAns = s;
                reverse(strAns.begin(), strAns.end());
                cout << ans.first << endl << strAns << endl;
                clean();
                return;
            }
            hsh = v;
        }
    }
    reverse(strAns.begin(), strAns.end());
    cout << ans.first << endl << strAns << endl;
    clean();
}

int main() {
    pw[0] = 1;
    for (long long i = 1; i < 300005; i++) {
        pw[i] = pw[i - 1] * 2;
        pw[i] %= mod;
    }
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
