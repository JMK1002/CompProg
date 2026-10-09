//
// Created by JMKov on 4/17/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

vector<int> sieve(int n) {
    bool prime[n - 1];
    for (int i = 0; i < n - 1; i++) {
        prime[i] = true;
    }
    for (int i = 0; i * i < n; i++) {
        if (!prime[i]) {
            continue;
        }
        int val = i + 2;
        for (int j = i * 2 + 2; j < n - 1; j += i + 2) {
            prime[j] = false;
        }
    }
    vector<int> primeVals(0);
    for (int i = 0; i < n - 1; i++) {
        if (prime[i]) {
            primeVals.insert(primeVals.begin() + primeVals.size(), i + 2);
        }
    }
    return primeVals;
}

int main() {
    int n;
    cin >> n;
    long long gcd;
    cin >> gcd;
    for (int i = 1; i < n; i++) {
        long long a;
        cin >> a;
        gcd = __gcd(gcd, a);
    }
    int ans = 1;
    if (gcd == 1) {
        cout << 1 << endl;
        return 0;
    }
    long long aaaa = gcd;
    for (long long i = 2; (i - 1) * (i - 1) <= aaaa; i++) {
        if (gcd % i == 0) {
            int count = 0;
            while (gcd % i == 0) {
                gcd /= i;
                count++;
            }
            ans *= (count + 1);
            count = 0;
        }
    }
    if (ans == 1) {
        cout << 2 << endl;
        return 0;
    }
    if (gcd != 1) {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}