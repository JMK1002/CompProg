//
// Created by JMKov on 3/2/2024.
//
#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long k, x, a;
        cin >> k >> x >> a;
        long long arr[x + 1];
        long long s = 0;
        bool ans = true;
        for (long long i = 0; i < x; i++) {
            arr[i] = (s) / (k - 1) + 1;
            if (arr[i] * (k - 1) <= s) {
                ans = false;
                break;
            }
            s += arr[i];
        }
        if ((a - s) * (k - 1) <= s) {
            ans = false;
        }
        if (!ans) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}