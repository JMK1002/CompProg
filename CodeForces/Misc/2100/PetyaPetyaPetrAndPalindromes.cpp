//
// Created by JMKov on 7/14/2024.
//
#include <iostream>
#include <vector>

using namespace std;

long long n, k;
long long arr[200005];
vector<long long> inds[200005][2];

int main() {
    cin >> n >> k;
    long long ans = k / 2 * (n - k + 1);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        long long cnt = lower_bound(inds[arr[i]][(i % 2) ^ !(k % 2)].begin(), inds[arr[i]][(i % 2) ^ !(k % 2)].end(), n - abs(n - i - k + 2) - 1) - lower_bound(inds[arr[i]][(i % 2) ^ !(k % 2)].begin(), inds[arr[i]][(i % 2) ^ !(k % 2)].end(), abs(i - k + 1));
        inds[arr[i]][i % 2].push_back(i);
        ans -= cnt;
//        cout << cnt << endl;
    }
    cout << ans << endl;
    return 0;
}