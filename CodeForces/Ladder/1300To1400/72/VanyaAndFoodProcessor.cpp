//
// Created by JMKov on 4/25/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, h, k;
    cin >> n >> h >> k;
    long long ans = 0;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long a = 0;
    for (int i = 0; i < n; i++) {
        if (a + arr[i] > h) {
            ans += max((long long) 0, (a + arr[i] - h + k - 1) / k);
            a -= max((long long) 0, ((a + arr[i] - h + k - 1) / k) * k);
            a = max(a, (long long) 0);
        }
        a += arr[i];
    }
//    cout << a << endl;
    ans += a / k;
    ans += a % k != 0;
    cout << ans << endl;
    return 0;
}
//10 100 88 1 6 11 15 23 25 37 43 69 71