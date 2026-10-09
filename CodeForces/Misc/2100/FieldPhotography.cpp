//
// Created by JMKov on 7/20/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    istream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n;

    int pw[31];
    int ans[31];
    vector<pair<int, bool>> events[31];
    for (int i = 0; i < 31; i++) {
        pw[i] = 0;
        ans[i] = 0;
    }

    pw[0] = 1;
    for (int i = 1; i < 31; i++) pw[i] = pw[i - 1] << 1;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = 0; j < 31; j++) {
            if (r - l + 1 >= pw[j]) {
                events[j].push_back({0, true});
                events[j].push_back({pw[j], false});
                continue;
            }

            int a = l % pw[j];
            int b = r % pw[j];
            if (b < a) {
                events[j].push_back({0, true});
                events[j].push_back({pw[j], false});
            }
            events[j].push_back({a, true});
            events[j].push_back({b + 1, false});
        }
    }

    for (int i = 0; i < 31; i++) {
        sort(events[i].begin(), events[i].end());
        int cnt = 0;
        for (pair<int, int> p : events[i]) {
            cnt += (p.second) ? 1 : -1;
            ans[i] = max(cnt, ans[i]);
        }
    }

    cin >> q;
    while (q--) {
        int z;
        cin >> z;
        int lsb = 0;
        while (z % 2 == 0) {
            z >>= 1;
            lsb++;
        }
        cout << ans[lsb] << endl;
    }
    return 0;
}