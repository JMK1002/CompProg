//
// Created by JMKov on 9/14/2024.
//
#include <iostream>
#include <vector>

using namespace std;

long long n, m;
vector<vector<bool>> arr;
vector<vector<bool>> explored;
vector<vector<long long>> pre;
vector<vector<long long>> unpre;
vector<long long> row;
vector<long long> col;
long long cnt = 0;
long long mnx = 1000000000;
long long mxx = -1;
long long mny = 1000000000;
long long mxy = -1;

void add(long long x1, long long y1, long long x2, long long y2, long long amnt) {
    pre[x1][y1] += amnt;
    pre[x1][y2 + 1] += amnt * -1;
    pre[x2 + 1][y1] += amnt * -1;
    pre[x2 + 1][y2 + 1] += amnt;
}

void dfs(long long x, long long y) {
    if (x < 0 || x >= n || y < 0 || y >= m || explored[x][y] || !arr[x][y]) return;
    explored[x][y] = true;
    cnt++;
    mnx = min(mnx, x);
    mxx = max(mxx, x);
    mny = min(mny, y);
    mxy = max(mxy, y);

    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}

void solve() {
    cin >> n >> m;
    pre.push_back({0});
    for (long long i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr.push_back({});
        unpre.push_back({});
        explored.push_back({});
        pre.push_back({0});
        for (long long j = 0; j < m; j++) {
            arr[i].push_back(s[j] == '#');
            unpre[i].push_back(0);
            explored[i].push_back(false);
            pre[i].push_back(0);
        }
    }
    for (long long i = 0; i < m; i++) pre[n].push_back(0);
    for (long long i = 0; i <= n; i++) pre[i].push_back(0);

    for (long long i = 0; i < n; i++) row.push_back(0);
    for (long long i = 0; i < m; i++) col.push_back(0);

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) row[i] += !arr[i][j];
    }
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < n; j++) col[i] += !arr[j][i];
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (explored[i][j] || !arr[i][j]) continue;

            dfs(i, j);

            mnx--;
            mxx++;
            mny--;
            mxy++;
            mnx = max(0ll, mnx);
            mny = max(0ll, mny);
            mxx = min(mxx, n - 1);
            mxy = min(mxy, m - 1);
            add(mnx, mny, mxx, mxy, -1 * cnt);
            add(0, mny, n - 1, mxy, cnt);
            add(mnx, 0, mxx, m - 1, cnt);

            cnt = 0;
            mnx = 1000000000;
            mxx = -1;
            mny = 1000000000;
            mxy = -1;
        }
    }

    for (long long i = n; i >= 1; i--) {
        for (long long j = m; j >= 1; j--) {
            long long a = (i == n) ? 0 : unpre[i][j - 1];
            long long b = (j == m) ? 0 : unpre[i - 1][j];
            long long c = (i == n || j == m) ? 0 : unpre[i][j];
            unpre[i - 1][j - 1] = pre[i][j] + a + b - c;
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) for (long long j = 0; j < m; j++) {
        ans = max(unpre[i][j] + row[i] + col[j] - !arr[i][j], ans);
    }
    cout << ans << endl;

    arr.clear();
    explored.clear();
    pre.clear();
    unpre.clear();
    row.clear();
    col.clear();
    cnt = 0;
    mnx = 1000000000;
    mxx = -1;
    mny = 1000000000;
    mxy = -1;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}