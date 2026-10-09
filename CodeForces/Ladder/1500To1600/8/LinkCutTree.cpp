//
// Created by JMKov on 5/7/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long l, r, k;
    cin >> l >> r >> k;
    vector<long long> ans;
    if (l == 1) ans.push_back(1);
    long long v = 1;
    while (v <= r / k) {
        v *= k;
        if (v >= l) {
            ans.push_back(v);
        }
    }
    if (ans.empty()) {
        cout << -1 << endl;
    }
    else {
        for (long long i : ans) {
            cout << i << " ";
        }
    }
}