//
// Created by JMKov on 7/19/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        vector<int> ind[200];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
            ind[arr[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 200; i++) ans = max(ans, (int) ind[i].size());
        for (int i = 0; i < 200; i++) {
            for (int k = 0; k < ind[i].size() / 2; k++) {
                for (int j = 0; j < 200; j++) {
                    if (i == j) continue;
                    int d1 = distance(ind[j].begin(), lower_bound(ind[j].begin(), ind[j].end(), ind[i][k]));
                    int d2 = distance(lower_bound(ind[j].begin(), ind[j].end(), ind[i][ind[i].size() - 1 - k]), ind[j].end());
                    int sum = ind[j].size() - d1 - d2;
                    ans = max(ans, (k + 1) * 2 + sum);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}