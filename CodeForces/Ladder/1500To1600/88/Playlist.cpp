//
// Created by JMKov on 6/2/2023.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    istream::sync_with_stdio(false);
    long long k, n;
    cin >> n >> k;
    vector<pair<long long, long long>> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());
    multiset<long long> sorted;
    for (int i = 0; i < k; i++) sorted.insert(0);
    long long sum = 0;
    long long ans = 0;
    for (long long i = n - 1; i >= 0; i--) {
        if (arr[i].second <= (*sorted.begin())) {
            ans = max(sum * arr[i].first, ans);
            continue;
        }
        sum -= *sorted.begin();
        sorted.insert(arr[i].second);
        sorted.erase(sorted.begin());
        sum += arr[i].second;
        ans = max(sum * arr[i].first, ans);
    }
    cout << ans << endl;
    return 0;
}
// 1 15
// 6 3
// 7 4
// 8 6