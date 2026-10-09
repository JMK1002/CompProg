//
// Created by JMKov on 6/15/2023.
//
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        map<long long, long long> count;
        map<long long, set<long long>> balls;
        long long arr[n];
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            balls[arr[i]].insert(0);
        }
        for (long long i = 1; i <= m; i++) {
            long long p;
            cin >> p;
            p--;
            long long val = arr[p];
            cin >> arr[p];
            count[val] += i - (*balls[val].begin());
            balls[val].erase(balls[val].begin());
            balls[arr[p]].insert(i);
        }
        for (long long i = 0; i < n; i++) {
            long long val = arr[i];
            count[val] += m - (*balls[val].begin()) + 1;
            balls[val].erase(balls[val].begin());
        }
        long long ans = 0;
        long long totalPairs = (m + 1) * m / 2;
        for (auto p : count) {
//            cout << p.first << " " << p.second << endl;
            ans += totalPairs - (m - p.second + 1) * (m - p.second) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}