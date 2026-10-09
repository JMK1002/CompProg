//
// Created by JMKov on 8/6/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

long long prefix[500010];
long long arr[500010];
long long n, k;

long long evalEnd(long long ind) {
    long long v = distance(lower_bound(arr, arr + n, ind), arr + n);
    return prefix[n] - prefix[n - v] - v * ind;
}

long long evalStart(long long ind) {
    long long v = distance(arr, lower_bound(arr, arr + n, ind));
    return v * ind - prefix[v];
}

int main() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (long long i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    long long ep;
    long long sp;
    long long low = arr[0];
    long long high = arr[n - 1];
    while (low < high) {
        long long mid = (low + high) / 2;
        if (evalEnd(mid) == k) {
            low = mid;
            break;
        }
        else if (evalEnd(mid) < k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    low += (evalEnd(low) > k);
    ep = low;
    low = arr[0];
    high = arr[n - 1];
    while (low < high) {
        long long mid = (low + high) / 2;
        if (evalStart(mid) == k) {
            low = mid;
            break;
        }
        else if (evalStart(mid) < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    low -= (evalStart(low) > k);
    sp = low;
//    cout << sp << " " << ep << endl;
//    for (long long i = 0; i < n; i++) cout << arr[i] << " ";
//    cout << endl;
    cout << max(ep - sp, (long long) (prefix[n] % n != 0)) << endl;
    return 0;
}
