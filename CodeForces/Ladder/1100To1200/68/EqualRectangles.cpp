//
// Created by JMKov on 3/28/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> lengths(4 * n);
        for (int i = 0; i < 4 * n; i++) {
            cin >> lengths[i];
        }
        sort(lengths.begin(), lengths.end());
        int product = lengths[lengths.size() - 1] * lengths[0];
        bool ans = true;
        for (int i = 0; i < n * 2; i++) {
            if (lengths[i] * lengths[lengths.size() - 1 - i] != product) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i < n * 4; i += 2) {
            if (lengths[i] != lengths[i - 1]) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}