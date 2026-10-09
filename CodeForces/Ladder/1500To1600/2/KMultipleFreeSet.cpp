//
// Created by JMKov on 5/5/2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    map<long long, bool> contains;
    map<long long, bool> explored;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        contains[arr[i]] = true;
    }
    long long ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int count = 0;
        long long index = arr[i];
        while (contains[index] && !explored[index]) {
            count++;
            contains[index] = false;
//            cout << index << " ";
            index *= k;
        }
        ans += (count + 1) / 2;
//        cout << endl;
    }
    cout << ans << endl;
    return 0;
}