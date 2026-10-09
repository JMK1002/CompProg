//
// Created by JMKov on 3/27/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        input[i]--;
    }
    sorted = input;
    sort(sorted.begin(), sorted.end());
    int distinctInts = 1;
    for (int i = 1; i < sorted.size(); i++) {
        if (sorted[i] != sorted[i - 1]) {
            distinctInts++;
        }
    }
    if (distinctInts > 3) {
        cout << -1 << endl;
        return 0;
    }
//    cout << distinctInts << endl;
    switch (distinctInts) {
        case 1:
            cout << 0 << endl;
            return 0;
        case 2:
            cout << (((sorted[0] + sorted[n - 1]) % 2 == 0) ? (sorted[n - 1] - sorted[0]) / 2 : sorted[n - 1] - sorted[0]) << endl;
            return 0;
        case 3:
            int mid = -1;
            for (int i = 1; i < n; i++) {
                if (sorted[i] != sorted[i - 1]) {
                    mid = sorted[i];
                    break;
                }
            }
            if ((sorted[0] + sorted[n - 1]) % 2 == 1 || (sorted[0] + sorted[n - 1]) / 2 != mid) {
                cout << -1 << endl;
                return 0;
            }
            else {
                cout << ((sorted[n - 1] - sorted[0]) / 2) << endl;
                return 0;
            }
    }
    return 0;
}