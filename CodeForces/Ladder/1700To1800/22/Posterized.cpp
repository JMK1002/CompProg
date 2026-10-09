//
// Created by JMKov on 6/13/2023.
//
#include <iostream>
using namespace std;

int main() {
    int vals[256];
    for (int &i : vals) i = -1;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        int fill = max(0, v - k + 1);
        if (vals[v] != -1) {
            cout << vals[v] << " ";
            continue;
        }
        for (int pos = max(0, v - k + 1); pos <= v; pos++) {
            if (vals[pos] == -1) {
                vals[pos] = fill;
            }
            else if (v - vals[pos] + 1 <= k) {
                fill = vals[pos];
            }
            else {
                fill = pos + 1;
            }
        }
        cout << vals[v] << " ";
    }
    return 0;
}