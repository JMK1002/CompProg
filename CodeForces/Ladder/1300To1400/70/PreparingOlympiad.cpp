//
// Created by JMKov on 4/25/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < pow(2, n); i++) {
        int v = i;
        int s = 0;
        int mx = 0;
        int mn = 1000000000;
        for (int j = 0; j < n; j++) {
            if ((v & 1) == 1) {
                s += arr[j];
                mx = max(arr[j], mx);
                mn = min(arr[j], mn);
            }
            v = v >> 1;
        }
        if (s >= l && s <= r && (mx - mn) >= x) {
//            cout << s << " " << mx << " " << mn << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}