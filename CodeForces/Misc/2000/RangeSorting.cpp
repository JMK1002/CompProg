//
// Created by JMKov on 5/26/2024.
//
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

pair<int, int> arr[10000];
pair<int, int> srtd[10000];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        srtd[i] = arr[i];
    }
    sort(srtd, srtd + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) ans += j - i;
    }
    cout << ans << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            srtd[j] = arr[j];
        }
        sort(srtd + i, srtd + n);
        for (int j = 0; j < n; j++) cout << srtd[j].first << " ";
        cout << endl;
        int mx = 0;
        for (int j = i; j < n; j++) {
            mx = max(mx, arr[j].first);
            if (mx == srtd[j].first) {
                ans -= (n - j - 1);
                cout << i << " " << j << endl;
            }

        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}