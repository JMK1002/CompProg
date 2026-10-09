//
// Created by JMKov on 7/28/2023.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    long long prefix[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    prefix[0] = arr[0];
    multiset<long long> curr;
    curr.insert(arr[0]);
    for (long long i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        curr.insert(arr[i]);
    }
    curr.insert(0);
    for (long long i = 0; i < n; i++) {
//        cout << (prefix[n - 1] - prefix[i] * 2) << " " << prefix[i] << endl;
        curr.erase(curr.lower_bound(arr[i]));
        curr.insert(arr[i] * -1);
        if ((prefix[n - 1] - prefix[i] * 2) % 2 == 0 && curr.count((prefix[n - 1] - prefix[i] * 2) / 2)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}