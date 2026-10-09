//
// Created by JMKov on 8/4/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
long long arr[200005];
long long cnt[2];

void clean() {
    for (long long i = 0; i <= n; i++) arr[i] = 0;
    cnt[0] = 0;
    cnt[1] = 0;
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long highestOdd = 0;
    for (long long i = 0; i < n; i++) {
        cnt[arr[i] % 2]++;
        if (arr[i] % 2 == 1) highestOdd = i;
    }
    if (cnt[0] == 0 || cnt[1] == 0) {
        cout << 0 << endl;
        clean();
        return;
    }

    if (arr[n - 1] % 2 == 1) {
        cout << (arr[n - 1] % 2 == 0) + cnt[0] << endl;
    }
    else {
        long long sum = arr[highestOdd];
        for (long long i = 0; i < n; i++) {
            if (arr[i] % 2 == 0 && sum > arr[i]) sum += arr[i];
        }
//        cout << sum << endl;
        if (sum > arr[n - 1]) {
            cout << cnt[0] << endl;
        }
        else {
            cout << 1 + cnt[0] << endl;
        }
    }
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}