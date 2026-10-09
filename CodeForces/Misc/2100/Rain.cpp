//
// Created by JMKov on 7/20/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

long long n, m;
vector<pair<long long, long long>> arr;
map<long long, long long> events;
long long heights[200005];
long long req[200005];
bool ans[200005];

void solve() {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        long long x, p;
        cin >> x >> p;
        arr.push_back({x, p});
        events[x - p]++;
        events[x] -= 2;
        events[x + p]++;
    }
    vector<long long> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (long long a, long long b) {
        return arr[a] < arr[b];
    });
    sort(arr.begin(), arr.end());
    long long run = 0;
    long long slope = 0;
    long long amnt = 0;
    pair<long long, long long> prev = *events.begin();
    for (pair<long long, long long> p : events) {
        if (run == n) break;
        while (run < n && arr[run].first < p.first) {
            heights[run] = amnt;
            run++;
        }
        if (run == n) break;
        amnt += slope * (p.first - prev.first);
        slope += p.second;
        prev = p;
    }

    run = -2000000000000000;
    for (long long i = 0; i < n; i++) {
        run = max(run + (arr[i].first - ((i - 1 < 0) ? 0 : arr[i - 1].first)), (heights[i] - m <= 0) ? -2000000000000000 : heights[i] - m);
        req[i] = max(req[i], run);
    }
    run = -2000000000000000;
    for (long long i = n - 1; i >= 0; i--) {
        run = max(run + (((i + 1 >= n) ? 0 : arr[i + 1].first) - arr[i].first), (heights[i] - m <= 0) ? -2000000000000000 : heights[i] - m);
        req[i] = max(req[i], run);
    }
    for (long long i = 0; i < n; i++) ans[ord[i]] = (arr[i].second >= req[i]);
    for (long long i = 0; i < n; i++) cout << ans[i];
    cout << endl;
    arr.clear();
    events.clear();
    for (long long i = 0; i <= n; i++) {
        heights[i] = 0;
        req[i] = 0;
        ans[i] = false;
    }

}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}