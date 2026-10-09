//
// Created by JMKov on 3/25/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int theorems[n];
    bool awake[n];
    int weighedPrefix[n];
    int unweighedPrefix[n];
    for (int i = 0; i < n; i++) {
        cin >> theorems[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> awake[i];
    }
    weighedPrefix[0] = theorems[0] * awake[0];
    unweighedPrefix[0] = theorems[0];
    for (int i = 1; i < n; i++) {
        weighedPrefix[i] = weighedPrefix[i - 1] + theorems[i] * awake[i];
        unweighedPrefix[i] = unweighedPrefix[i - 1] + theorems[i];
    }
    int mx = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int above = weighedPrefix[n - 1] - weighedPrefix[k + i - 1];
        int middle;
        int below;
        if (i == 0) {
            middle = unweighedPrefix[k - 1];
            below = 0;
        }
        else {
            middle = unweighedPrefix[k + i - 1] - unweighedPrefix[i - 1];
            below = weighedPrefix[i - 1];
        }
        mx = max(mx, below + middle + above);
    }
    cout << mx << endl;
    return 0;
}