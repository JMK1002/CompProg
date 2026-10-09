//
// Created by JMKov on 8/7/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        ans += arr[i] / 2;
        arr[i] %= 2;
    }
    long long b = 0;
    long long w = 0;
    for (long long i = 0; i < n; i++) {
        if (i & 1) {
            b += arr[i];
        }
        else {
            w += arr[i];
        }
    }
    cout << ans + min(b, w) << endl;
    return 0;
}