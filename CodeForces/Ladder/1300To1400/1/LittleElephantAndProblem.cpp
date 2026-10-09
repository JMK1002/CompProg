//
// Created by JMKov on 4/1/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b = a;
    sort(a.begin(), a.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += b[i] != a[i];
    }
    cout << ((count > 2) ? "NO" : "YES") << endl;
    return 0;
}