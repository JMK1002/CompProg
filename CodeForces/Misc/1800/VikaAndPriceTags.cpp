//
// Created by JMKov on 4/28/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

void op(int& a, int& b) {
    int x = abs(a - b);
    a = b;
    b = x;
}

void solve() {
    int n;
    cin >> n;
//    n *= n;
    int a[n], b[n], cnt[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
//        a[i] = i / n;
        cnt[i] = 0;
    }
    bool worked = true;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
//        b[i] = i % n;
        if (!a[i] && !b[i]) {
            cnt[i] = (i > 0) ? cnt[i - 1] : -1;
            continue;
        }
//            int l = a[i];
//            int m = b[i];
//            int asdf = 0;
//            while (l != 0) {
//                int x = abs(l - m);
//                l = m;
//                m = x;
//                asdf++;
//            }
        while (a[i] != 0) {
            while (a[i] >= b[i]) {
                op(a[i], b[i]);
                cnt[i]++;
            }
            if (a[i] == 0) break;
            cnt[i] += (b[i] / a[i]);
            cnt[i] += (b[i] / a[i]) / 2;
            int v = (b[i] / a[i]) + 2 /* -3*/;
            if (v % 2 == 1) {
                int x = b[i] % a[i];
                b[i] = a[i];
                a[i] = x;
                cnt[i]++;
            }
            else {
                b[i] %= a[i];
            }
        }
//        cout << asdf << " " << cnt[i] << endl;
        if (worked && i != 0 && cnt[i - 1] != -1 && cnt[i] % 3 != cnt[i - 1] % 3) {
            cout << "NO" << endl;
            worked = false;
        }
    }
    if (!worked) return;
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}