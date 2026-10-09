//
// Created by JMKov on 6/11/2023.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        vector<int> bruh;
        int v = 0;
        int low = 0;
        int high = 0;
        int xCount = 0;
        for (int i = 0; i < n; i++) {
            bruh.push_back(v);
            xCount += (v == x);
            v += (s[i] == '0') ? 1 : -1;
            low = min(v, low);
            high = max(v, high);
        }
        long long ans = 0;
        int pos = x;
        if (v == 0 && xCount >= 1) {
            cout << -1 << endl;
            continue;
        }
        else if (v == 0) {
            cout << 0 << endl;
            continue;
        }

//        while ((v < 0 && pos <= high) || (v > 0 && pos >= low)) {
//            ans += count[pos];
//            pos -= v;
//        }
        for (int i : bruh) {
            if (((i <= x && v > 0) || (i >= x && v < 0)) && (i - x) % (v * -1) == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}