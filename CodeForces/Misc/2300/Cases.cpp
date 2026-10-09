//
// Created by JMKov on 7/31/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n, k, c;
string s;
int arr[300000];
int masks[300000];
bool bad[300000];
bool explored[300000];
int cnt[20];

void dfs(int v) {
    explored[v] = true;
    for (int i = 0, amnt = 1; i < c; i++, amnt <<= 1) {
        if (amnt & v) continue;
        if (!explored[amnt | v]) dfs(amnt | v);
        bad[v] |= bad[amnt | v];
    }
}

void solve() {
    cin >> n >> c >> k >> s;
    for (int i = 1; i <= n; i++) {
        char a = s[i - 1];
        arr[i] = (1 << (a - 'A'));
        cnt[a - 'A']++;
        if (i - k > 0) cnt[s[i - k - 1] - 'A']--;
        for (int j = 0; j < 20; j++) {
            masks[i] |= (1 << j) * (cnt[j] > 0);
        }
    }
    for (int i = k; i <= n; i++) {
        bad[(1 << c) - 1 - masks[i]] = true;
        explored[(1 << c) - 1 - masks[i]] = true;
    }

    for (int i = 0; i < (1 << c); i++) if (!explored[i]) dfs(i);

    pair<int, int> mn = {INT_MAX, INT_MAX};
    for (int i = 0; i < (1 << c); i++) {
        if (!bad[i] && (i & arr[n])) mn = min(mn, {__builtin_popcount(i), i});
    }
    cout << mn.first << endl;

    for (int i = 0; i <= max(n, (1 << c) + 1); i++) {
        arr[i] = 0;
        masks[i] = 0;
        bad[i] = false;
        explored[i] = false;
    }
    for (int i = 0; i < 20; i++) cnt[i] = 0;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}