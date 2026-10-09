//
// Created by JMKov on 4/3/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sorted = a;
    sort(sorted.begin(), sorted.end());
    int p1 = 0;
    int p2 = n;
    for (int i = 1; i < n; i++) {
        if (sorted[i] != sorted[i - 1]) {
            p2 = i - 1;
            break;
        }
    }
    int ans = 0;
    while (p2 < n) {
        if (sorted[p1] < sorted[p2]) {
            p1++;
            p2++;
            ans++;
        }
        else {
            p2++;
        }
    }
    cout << ans << endl;
    return 0;
}