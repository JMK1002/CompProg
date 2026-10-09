//
// Created by JMKov on 7/27/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    cin >> k;
    if (!(k & 1)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int vert = (2 * k - 1) * 2;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= k - 1; i++) ans.emplace_back(2 * k - 1, i);
    for (int i = 1; i <= k - 1; i++) {
        for (int j = k; j <= 2 * k - 2; j++) {
            ans.emplace_back(i, j);
        }
    }
    for (int i = k; i <= 2 * k - 2; i += 2) ans.emplace_back(i, i + 1);
    cout << vert << " " << ans.size() * 2 + 1 << endl;
    for (pair<int, int> p : ans) {
        cout << p.first << " " << p.second << endl;
        cout << p.first + 2 * k - 1 << " " << p.second + 2 * k - 1 << endl;
    }
    cout << 2 * k - 1 << " " << 4 * k - 2 << endl;
    return 0;
}