#include <iostream>
#include <map>
using namespace std;

string s;
long long n, k, w, h;
map<pair<long long, long long>, long long> cnt;

void solve() {
    cin >> n >> k >> w >> h >> s;
    w *= 2;
    h *= 2;
    pair<long long, long long> vec = {0, 0};
    for (char c : s) {
        if (c == 'U') vec.second++;
        if (c == 'D') vec.second--;
        if (c == 'R') vec.first++;
        if (c == 'L') vec.first--;
    }
    vec.first = (vec.first % w + w) % w;
    vec.second = (vec.second % h + h) % h;
    pair<long long, long long> run = {0, 0};
    for (long long i = 0; i < k; i++) {
        cnt[run]++;
        run.first += vec.first;
        run.second += vec.second;
        run.first %= w;
        run.second %= h;
    }
    long long ans = 0;
    run = {0, 0};
    for (char c : s) {
        if (c == 'U') run.second--;
        if (c == 'D') run.second++;
        if (c == 'R') run.first--;
        if (c == 'L') run.first++;
        run.first = (run.first % w + w) % w;
        run.second = (run.second % h + h) % h;
        ans += cnt[run];
        // cout << run.first << " " << run.second << endl;
    }
    cout << ans << endl;
    cnt.clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}