//
// Created by JMKov on 4/26/2023.
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
    std::sort(a.begin(), a.end());
    cout << a[n - n / 2 - 1] << endl;

    return 0;
}