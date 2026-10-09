//
// Created by JMKov on 7/16/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

long long mod = 998244353;

long long fact[300010];

int main() {
    long long n;
    cin >> n;
    pair<long long, long long> arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    fact[0] = 1;
    for (long long i = 1; i <= 300000; i++) {
        fact[i] = (long long) fact[i - 1] * i % mod;
    }
    long long ans = 0;
    sort(arr, arr + n, [](pair<long long, long long> a, pair<long long, long long> b) {
        return a.second < b.second;
    });
    long long count = 1;
    long long curr = 1;
    for (long long i = 1; i < n; i++) {
        if (arr[i].second == arr[i - 1].second) count++;
        else {
            curr *= fact[count];
            curr %= mod;
            count = 1;
        }
    }
    curr *= fact[count];
    curr %= mod;
//    cout << curr << endl;
    ans += curr;
    ans %= mod;
    sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    count = 1;
    curr = 1;
    for (long long i = 1; i < n; i++) {
        if (arr[i].first == arr[i - 1].first) count++;
        else {
            curr *= fact[count];
            curr %= mod;
            count = 1;
        }
    }
    curr *= fact[count];
    curr %= mod;
//    cout << curr << endl;
    ans += curr;
    ans %= mod;
    count = 1;
    curr = 1;
    for (long long i = 1; i < n; i++) {
        if (arr[i - 1].second > arr[i].second) {
            ans %= mod;
            ans = (fact[n] - ans);
            while (ans < 0) ans += mod;
            ans %= mod;
            cout << ans << endl;
            return 0;
        }
    }

    for (long long i = 1; i < n; i++) {
        if (arr[i].first == arr[i - 1].first && arr[i].second == arr[i - 1].second) count++;
        else {
            curr *= fact[count];
            curr %= mod;
            count = 1;
        }
    }
    curr *= fact[count];
    curr %= mod;
//    cout << curr << endl;
    ans -= curr;
    ans %= mod;
    ans = (fact[n] - ans);
    while (ans < 0) ans += mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}