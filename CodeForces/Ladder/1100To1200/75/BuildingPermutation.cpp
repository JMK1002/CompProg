//
// Created by JMKov on 3/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - (i + 1));
    }
    cout << ans << endl;
    return 0;
}