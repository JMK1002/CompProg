//
// Created by JMKov on 4/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mn(n);
    vector<int> mx(n);
    bool a[n];
    for (int i = 0; i < n; i++) {
        mn[i] = 1000000000;
        mx[i] = -1;
        a[i] = false;
    }
    for (int i = 0; i < n; i++) {
        int asdflol;
        cin >> asdflol;
        int lastVal = 1000000000;
        for (int j = 0; j < asdflol; j++) {
            int b;
            cin >> b;
            a[i] = a[i] || (b > lastVal);
            mn[i] = min(b, mn[i]);
            mx[i] = max(b, mx[i]);
            lastVal = b;
        }
        if (a[i]) {
            mn[i] = -1;
            mx[i] = 1000000000;
        }
    }
    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        double t = mn[i] + 0.5;
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (t < mx[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        while (low < n && mx[low] <= mn[i]) {
            low++;
        }
//        cout << low << endl;
        ans += n - low;
    }
    cout << ans << endl;
    return 0;
}
// 0 6 7
// 2 6 9