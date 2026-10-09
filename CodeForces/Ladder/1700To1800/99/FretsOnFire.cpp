//
// Created by JMKov on 7/15/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<long long> asdf(n - 1);
    for (long long i = 0; i < n - 1; i++) asdf[i] = (arr[i + 1] - arr[i]);
    sort(asdf.begin(), asdf.end());
    long long prefix[n];
    prefix[n - 1] = 0;
    for (long long i = n - 2; i >= 0; i--) prefix[i] = prefix[i + 1] + asdf[i];
    long long m;
    cin >> m;
    while (m--) {
        long long u, v;
        cin >> u >> v;
        v -= u;
        u = 0;
        long long s = v + 1 + prefix[0];
//        cout << s << " ";
//        for (long long i = 0; i < n - 1; i++) {
//            s += min(asdf[i], v + 1);
//        }
        long long dist = distance(asdf.begin(), lower_bound(asdf.begin(), asdf.end(), v  + 1));
        s -= prefix[dist] - (v + 1) * (n - 1 - dist);
        cout << s << " ";
    }
    return 0;
}
// 0 2 1 1 4