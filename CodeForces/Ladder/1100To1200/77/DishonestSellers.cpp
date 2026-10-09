//
// Created by JMKov on 3/31/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int as = 0;
    int bs = 0;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        as += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        diff[i] = a[i] - b[i];
        bs += b[i];
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < k; i++) {
        bs += diff[i];
    }
    for (int i = k; i < n; i++) {
        if (diff[i] <= 0) {
            bs += diff[i];
        }
    }
    cout << bs << endl;
    return 0;
}