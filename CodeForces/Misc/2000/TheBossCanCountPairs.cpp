//
// Created by JMKov on 3/9/2024.
//
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int a[200004];
int b[200004];
map<pair<int, int>, int> mp;

int get(int a, int b) {
    int ans = mp[{a, b}];
    if (ans == 0) mp.erase({a, b});
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) mp[{a[i], b[i]}]++;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] * a[i] > 2 * n) continue;
            ans += get(a[i], a[i] * a[i] - b[i]);
        }

        for (int i = 2; i * i <= 2 * n; i += 2) {
            ans -= get(i, i * i / 2);
        }

        ans /= 2;

        for (int i = 0; i < n; i++) {
            for (int j = 1; a[i] * j <= 2 * n && j < a[i]; j++) {
                ans += get(j, a[i] * j - b[i]);
            }
        }
        cout << ans << endl;
        mp.clear();
    }
    return 0;
}