#include <iostream>
using namespace std;

long long n, m;
string s;
long long arr[1003][1003];
pair<long long, long long> copyArr[1003][1003];
long long cnt[2][1003]; // * 0 is row 1 is col
pair<long long, long long> sum[2][1003]; // * 0 is row 1 is col

void fl(pair<long long, long long> pos) {
    pair<long long, long long> res = {0, 0};
    if (cnt[0][pos.first] == 1) res = {1 - sum[0][pos.first].first, -1 * sum[0][pos.first].second};
    if (cnt[1][pos.second] == 1) res = {1 - sum[1][pos.second].first, -1 * sum[1][pos.second].second};

    cnt[0][pos.first]--;
    cnt[1][pos.second]--;
    sum[0][pos.first].first += res.first;
    sum[0][pos.first].second += res.second;
    sum[1][pos.second].first += res.first;
    sum[1][pos.second].second += res.second;
    // cout << pos.first << " " << pos.second << " " << res.first << " " << res.second << endl;
    copyArr[pos.first][pos.second] = res;
}

void solve() {
    cin >> n >> m >> s;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> arr[i][j];
            sum[0][i].second += arr[i][j];
            sum[1][j].second += arr[i][j];
        }
    }

    pair<long long, long long> pos = {0, 0};
    cnt[0][pos.first]++;
    cnt[1][pos.second]++;
    for (char c : s) {
        if (c == 'D') pos.first++;
        else pos.second++;
        cnt[0][pos.first]++;
        cnt[1][pos.second]++;
    }


    for (long long i = 0; i < n; i++) for (long long j = 0; j < m; j++) copyArr[i][j] = {0, arr[i][j]};

    pos = {0, 0};
    fl(pos);
    for (char c : s) {
        if (c == 'D') pos.first++;
        else pos.second++;
        fl(pos);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cout << copyArr[i][j].second << " ";
        }
        cout << endl;
    }
    for(long long i = 0; i <= n; i++) for (long long j = 0; j <= m; j++) {
        arr[i][j] = 0;
        copyArr[i][j] = {0, 0};
    }
    for (long long i = 0; i <= max(n, m); i++) {
        cnt[0][i] = 0;
        cnt[1][i] = 0;
        sum[0][i] = {0, 0};
        sum[1][i] = {0, 0};
    }
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