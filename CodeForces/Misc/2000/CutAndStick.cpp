//
// Created by JMKov on 6/18/2024.
//
#include <iostream>
#include <set>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int amnt = 40;

int n, q;
int arr[300004];
vector<int> cnt[300004];

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = 1;
        cnt[arr[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
//        l = 1;
//        r = n;
        l--; r--;
        int ans = 1;
        for (int j = 0; j < amnt; j++) {
            int ind = uniform_int_distribution<int>(l, r)(rng);
            int val = arr[ind];
            int x = upper_bound(cnt[val].begin(), cnt[val].end(), r) - lower_bound(cnt[val].begin(), cnt[val].end(), l);
            ans = max(ans, 2 * x - (r - l + 1));
        }
        cout << ans << endl;
    }
    return 0;
}