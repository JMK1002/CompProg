//
// Created by JMKov on 5/25/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long differences[n - 1];
    for (long long i = 0; i < n - 1; i++) differences[i] = abs(arr[i] - arr[i + 1]);
    long long ans = differences[0];
    long long v = differences[0];
    long long count = v;
    for (long long i = 1; i < n - 1; i++) {
        v += ((i & 1) ? -1 : 1) * differences[i];
        count += ((i & 1) ? -1 : 1) * differences[i];
        if (count < 0) {
            v -= count;
            count = 0;
        }
        ans = max(ans, v);
    }
    ans = max(ans, v);
    if (n == 2) {
        cout << ans << endl;
        return 0;
    }
    v = differences[1];
    count = v;
    for (long long i = 2; i < n - 1; i++) {
        v += ((i & 1) ? 1 : -1) * differences[i];
        count += ((i & 1) ? 1 : -1) * differences[i];
        if (count < 0) {
            v -= count;
            count = 0;
        }
        ans = max(ans, v);
    }
    ans = max(ans, v);
    cout << ans << endl;
    return 0;
}