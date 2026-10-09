//
// Created by JMKov on 4/23/2024.
//
#include <iostream>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long arr[n];
    long long cnt = 0;
    long long dec[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (long long i = 1; i < n; i++) {
        cnt += (arr[i - 1] >= arr[i]);
    }
    long long cnt2 = 0;
    long long ans = 1000000000;
    for (long long i = 0; i < n; i++) {
        bool isMultipliedByNegative = (i > 0);
        ans = min(ans, isMultipliedByNegative + cnt + cnt2);

        if (i + 1 < n)
            cnt -= (arr[i] >= arr[i + 1]);
        if (i > 0)
            cnt2 += (arr[i - 1] <= arr[i]);
    }
    cout << ans << endl;

//    long long arr[n];
//    long long inc[n];
//    long long dec[n];
//    for (long long i = 0; i < n; i++) {
//        cin >> arr[i];
//        inc[i] = 0;
//        dec[i] = 0;
//    }
//    for (long long i = 1; i < n; i++) {
//        inc[i] += (arr[i - 1] >= arr[i]);
//        dec[i] += (arr[i - 1] <= arr[i]);
//    }
//    for (long long i = n - 2; i >= 0; i--) inc[i] += inc[i + 1];
//    for (long long i = 1; i < n; i++) dec[i] += dec[i - 1];
//
//    long long ans = min(inc[0], dec[n - 1] + 1);
//    for (long long i = 1; i < n - 1; i++) {
//        ans = min(ans, inc[i + 1] + dec[i - 1] + 1);
//    }
//    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}