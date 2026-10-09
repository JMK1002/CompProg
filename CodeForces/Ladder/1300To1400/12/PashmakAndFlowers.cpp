//
// Created by JMKov on 4/5/2023.
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
    if (a[0] == a[n - 1]) {
        cout << 0 << " " << (long long) n * (long long) (n - 1) / 2 << endl;
        return 0;
    }
    int start;
    int end;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) {
            start = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i - 1] != a[i]) {
            end = n - i;
            break;
        }
    }
    cout << a[n - 1] - a[0] << " " << (long long) start * (long long) end << endl;
    return 0;
}