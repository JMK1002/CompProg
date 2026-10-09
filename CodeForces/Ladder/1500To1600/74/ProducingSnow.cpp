//
// Created by JMKov on 5/28/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long vols[n];
    long long temps[n];
    long long ans[n];
    for (long long i = 0; i < n; i++) cin >> vols[i];
    for (long long i = 0; i < n; i++) cin >> temps[i];
    for (long long i = 0; i < n; i++) ans[i] = 0;
    vector<long long> tempPrefix(n + 1);
    tempPrefix[0] = 0;
    for (long long i = 1; i <=  n; i++) {
        tempPrefix[i] = tempPrefix[i - 1] + temps[i - 1];
    }
    long long locations[n];
    for (long long i = 0; i < n; i++) {
        long long target = vols[i] + tempPrefix[i];
        locations[i] = distance(tempPrefix.begin(), upper_bound(tempPrefix.begin(), tempPrefix.end(), target));
    }
//    for (long long i : locations) cout << i << " ";
//    cout << endl;
    long long prefixAns[n];
    for (long long i = 0; i < n; i++) prefixAns[i] = 1;
    for (long long i = 0; i < n; i++) {
        if (locations[i] - 1 >= n) continue;
        prefixAns[locations[i] - 1]--;
    }
    for (long long i = 0; i < n; i++) {
        if (locations[i] - 1 >= n) continue;
        ans[locations[i] - 1] += vols[i] - tempPrefix[locations[i] - 1] + tempPrefix[i];
    }
    long long count = 0;
    for (long long i = 0; i < n; i++) {
        count += prefixAns[i];
        ans[i] += count * temps[i];
        cout << ans[i] << " ";
    }
    return 0;
}