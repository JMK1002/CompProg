//
// Created by JMKov on 7/14/2023.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long arr[200010];
long long n;

long long count(long long v) {
    return (upper_bound(arr, arr + n, v) - lower_bound(arr, arr + n, v));
}

int main() {
    cin >> n;
    long long mx = 0;
    long long v = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (long long i = 0; i < n; i++) {
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        long long cnt = count(arr[i]);
        if (cnt > mx) {
            mx = cnt;
            v = arr[i];
        }
    }
    pair<long long, long long> asdf(0, 0);
    long long basdf = mx;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < 31; j++) {
            if (count(arr[i] + (1 << j))) {
                long long cnt = count(arr[i]) + count(arr[i] + (1 << j)) + count(arr[i] + (1 << (j + 1)));
                if (cnt > basdf) {
                    basdf = cnt;
                    asdf.first = i;
                    asdf.second = j;
                }
            }
        }
    }
    if (basdf <= mx) {
        cout << mx << endl;
        for (long long i = 0; i < mx; i++) cout << v << " ";
        return 0;
    }
    cout << basdf << endl;
    for (long long i = 0; i < count(arr[asdf.first]); i++) cout << arr[asdf.first] << " ";
    for (long long i = 0; i < count(arr[asdf.first] + (1 << asdf.second)); i++) cout << arr[asdf.first] + (1 << asdf.second) << " ";
    for (long long i = 0; i < count(arr[asdf.first] + (1 << (asdf.second + 1))); i++) cout << arr[asdf.first] + (1 << (asdf.second + 1)) << " ";
    return 0;
}