//
// Created by JMKov on 6/16/2024.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
pair<pair<int, int>, int> segs[2000];
string s;
string nums[1002];
int dp[1002];
vector<pair<pair<int, int>, int>> ans;

int hsh(char a, char b) {
    return (a - '0' + 1) * 11 + (b - '0' + 1);
}

int hsh(char a, char b, char c) {
    return hsh(a, b) * 11 + (c - '0' + 1);
}

void clean() {
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    ans.clear();
}

void solve() {
    for (int i = 0; i < 2000; i++) segs[i] = {{0, 0}, -1}; // might tle
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        for (int j = 0; j < m - 1; j++) {
            segs[hsh(nums[i][j], nums[i][j + 1])] = {{j, j + 1}, i};
        }
        for (int j = 0; j < m - 2; j++) {
            segs[hsh(nums[i][j], nums[i][j + 1], nums[i][j + 2])] = {{j, j + 2}, i};
        }
    }
    cin >> s;
    dp[0] = -1;
    for (int i = 2; i <= m; i++) {
        dp[i] = (i - 2 + 1) * (dp[i - 2] != 0 && (segs[hsh(s[i - 2], s[i - 1])].second != -1));
        if (dp[i] == 0) dp[i] = (i < 3) ? 0 : (i - 3 + 1) * (dp[i - 3] != 0 && (segs[hsh(s[i - 3], s[i - 2], s[i - 1])].second != -1));
    }
//    for (int i = 0; i <= m; i++) cout << dp[i] << " ";
//    cout << endl;

    if (dp[m] == 0) {
        cout << -1 << endl;
        clean();
        return;
    }

    int pos = m;
    while (pos != 0) {
        if (pos - dp[pos] + 1 == 2) {
            ans.push_back(segs[hsh(s[pos - 2], s[pos - 1])]);
        }
        else {
            ans.push_back(segs[hsh(s[pos - 3], s[pos - 2], s[pos - 1])]);
        }
        pos = dp[pos] - 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (pair<pair<int, int>, int> p : ans) cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second + 1 << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}