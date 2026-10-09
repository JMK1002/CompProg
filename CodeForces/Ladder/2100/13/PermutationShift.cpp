//
// Created by JMKov on 8/22/2023.
//
#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}