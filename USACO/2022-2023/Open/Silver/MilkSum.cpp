//
// Created by JMKov on 4/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[150003];
vector<long long> sorted;
long long pre[150003];

int main() {
    long long n;
    cin >> n;
    long long s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        sorted.push_back(arr[i]);
    }
    sort(sorted.begin(), sorted.end());
    for (long long i = 0; i < n; i++) {
        pre[i + 1] = sorted[i] + pre[i];
        s += (i + 1) * sorted[i];
    }
    long long q;
    cin >> q;
    while (q--) {
        long long i, j;
        cin >> i >> j;
        i--;
        long long i1 = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        long long i2 = lower_bound(sorted.begin(), sorted.end(), j) - sorted.begin();
//        cout << i1 << " " << i2 << endl;
        cout << s + pre[i1] - pre[i2] - (i1 + (i2 <= i1)) * arr[i] + (i2 + (i2 <= i1)) * j << endl;
    }
    return 0;
}