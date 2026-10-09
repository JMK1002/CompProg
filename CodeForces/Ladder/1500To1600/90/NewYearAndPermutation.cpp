//
// Created by JMKov on 6/3/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    long long k = 1;
    long long nmnk = 1;
    long long asdf[n + 1];
    for (int i = 1; i < n; i++) {
        nmnk *= i;
        nmnk %= m;
        asdf[n - i - 1] = nmnk;
    }
    asdf[n - 1] = 1;
//    for (int i : asdf) cout << i << " ";
//    cout << endl;
    for (int i = 1; i <= n; i++) {
        k *= i;
        k %= m;
        long long v = k * asdf[i - 1];
        v %= m;
        v *= (n - i + 1);
        v %= m;
        v *= (n - i + 1);
        v %= m;
        ans += v;
        ans %= m;
//        cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

//2 * 2 * 2 + 6 + 18
// (n - k + 1) * (n - k + 1) * k!
// k! * (n - k + 1)^2 * (n - 1)!

// 18 + 16 + 12
// 18 + 8  + 6