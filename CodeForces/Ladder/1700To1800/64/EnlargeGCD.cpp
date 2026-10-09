//
// Created by JMKov on 7/1/2023.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> cnt;
vector<int> primes;

void sieve(int n) {
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    for (int i = 2; i < n; i++) {
        if (explored[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j < n; j += i) explored[j] = true;
    }
}

void factor(int n) {
    for (int i = 0; primes[i] * primes[i] <= n && i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            cnt[primes[i]]++;
//            cout << primes[i] << endl;
        }
        while (n % primes[i] == 0) n /= primes[i];
    }
    if (n != 1) {
        cnt[n]++;
    }
}

int solve() {
    int n;
    cin >> n;
    int arr[n];
    cin >> arr[0] >> arr[1];
//    arr[0] = 2; arr[1] = 3;
    int gcd = __gcd(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        cin >> arr[i];
//        arr[i] = 999983;
        gcd = __gcd(gcd, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= gcd;
        factor(arr[i]);
    }
//    for (int i = 0; i < 100; i++) cout << primes[i] << " ";
//    return 0;
    int ans = 0;
    for (pair<int, int> i : cnt) ans = max(ans, i.second);
    if (ans == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << n - ans << endl;
    return 0;
}

int main() {
    istream::sync_with_stdio(0);
    cout.tie();
    cin.tie();
    sieve(4000);
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        factor(n);
//    }
    solve();
}