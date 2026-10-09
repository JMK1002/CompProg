//
// Created by JMKov on 9/18/2024.
//
#include <iostream>
using namespace std;

int n;
int arr[100005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}