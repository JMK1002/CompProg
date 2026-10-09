//
// Created by JMKov on 5/12/2023.
//
#include <iostream>
using namespace std;
long long asdf[100010];
long long count[100010];

int main() {
    long long n, x;
    cin >> n >> x;
    long long arr[n];
    if (x == 0) {
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            count[arr[i]]++;
        }
        for (long long i : count) {
            ans += (long long) i * (long long) (i - 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        asdf[arr[i]]++;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        ans += ((arr[i] ^ x) < 100010) * (asdf[arr[i] ^ x]);
    }
    cout << ans / 2 << endl;
    return 0;
}