//
// Created by JMKov on 6/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long h, n;
    cin >> h >> n;
    long long arr[n];
    long long mn = 0;
    long long index = 0;
    long long v = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        v += arr[i];
        if (v < mn) {
            mn = v;
            index = i + 1;
        }
    }
    h += mn;
    if (v >= 0 && h > 0) {
        cout << -1 << endl;
        return 0;
    }
    else if (h <= 0) {
        h -= mn;
        v = 0;
        for (int i = 0; i < n; i++) {
            v += arr[i];
            if (v * -1 >= h) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    long long ans = (h / v * -1 + (h % v != 0)) * n;
    h += v * (h / v * -1 + (h % v != 0));
    h -= mn;
//    cout << ans << " " << h << " " << endl;
    v = 0;
    for (int i = 0; i < n; i++) {
        v += arr[i];
        if (h + v <= 0) {
            cout << i + 1 + ans << endl;
            return 0;
        }
    }
//    h / v < x
    return 0;
}
// h - x * v < mn
//-999999999999