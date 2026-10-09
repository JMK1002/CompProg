//
// Created by JMKov on 6/14/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n + 1];
    for (int i = 0; i <= n; i++) arr[i] = 0;
    arr[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> factors;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                factors.push_back(j);
                if (x / j != j) {
                    factors.push_back(x / j);
                }
            }
        }
        sort(factors.begin(), factors.end());
        reverse(factors.begin(), factors.end());
        for (int j : factors) {
            if (j > n) continue;
//            cout << j << " ";
            arr[j] += arr[j - 1];
            arr[j] %= 1000000007;
        }
//        for (int j : arr) cout << j << " ";
//        cout << endl;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += arr[i];
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}