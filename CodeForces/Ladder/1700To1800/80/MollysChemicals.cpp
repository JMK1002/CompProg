//
// Created by JMKov on 7/8/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    long long prefix[n];
    cin >> arr[0];
    prefix[0] = arr[0];

    vector<long long> vals;
    vals.push_back(1);
    if (k == -1) {
        vals.push_back(-1);
    }
    else if (k != 1) {
        long long v = 1;
        while (v < 900000000000000) {
            v *= k;
            vals.push_back(v);
        }
    }
    map<long long, int> mp;
    mp[prefix[0]]++;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
        mp[prefix[i]]++;
    }
    long long ans = 0;
    for (long long j : vals) {
        ans += mp[j];
    }
//    cout << endl;
    for (int i = 0; i < n; i++) {
        mp[prefix[i]]--;
        for (long long j : vals) {
            if (prefix[i] > 0 && j > 0 && INT64_MAX - prefix[i] < j) continue;
            if (prefix[i] < 0 && j < 0 && INT64_MIN - prefix[i] > j) continue;
            ans += mp[prefix[i] + j];
        }
    }
    cout << ans << endl;
    return 0;
}