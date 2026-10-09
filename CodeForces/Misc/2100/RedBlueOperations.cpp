//
// Created by JMKov on 7/10/2024.
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

long long n, k, q;
long long arr[1005];
long long qArr[1005];

int main() {
    cin >> n >> q;
    for (long long i = 0; i < n; i++) cin >> arr[i];

    while (q--) {
        cin >> k;
        for (long long i = 0; i < n; i++) qArr[i] = arr[i];
        sort(qArr, qArr + n);
        int cnt = 0;
        for (long long i = k; i >= max((long long) 0, k - n + (n + k) % 2 + 1); i--) {
            qArr[k - i] += i;
            cnt++;
        }
        k -= cnt;
        k /= 2;
        long long s = 0;
        sort(qArr, qArr + n);
        for (long long i = 0; i < n; i++) s += qArr[i] - qArr[0];
        long long ans = qArr[0] - (max(max(k, (long long) 0) - s, (long long) 0) / n + 1 - (max(max(k, (long long) 0) - s, (long long) 0) % n == 0));
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
// 2 3
// 12 12
//