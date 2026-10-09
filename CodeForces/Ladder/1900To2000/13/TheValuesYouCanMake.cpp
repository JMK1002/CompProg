//
// Created by JMKov on 7/24/2023.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool dp[501][501][501];
bool works[501][501];

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    set<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 501; i++) for (int j = 0; j < 501; j++) dp[i][j][0] = true;
    dp[0][arr[0]][arr[0]] = true;
    works[0][arr[0]] = true;
    works[0][0] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 501; j++) {
            works[i][j] = works[i - 1][j] || (j >= arr[i] && works[i - 1][j - arr[i]]);
            if (j >= arr[i] && works[i - 1][j - arr[i]]) {
                for (int m = 0; m < 501 - arr[i]; m++) {
                    dp[i][j][m + arr[i]] |= dp[i - 1][j - arr[i]][m];
                    dp[i][j][m] |= dp[i - 1][j - arr[i]][m];
                }
            }
            if (dp[i - 1][j]) {
                for (int m = 0; m < 501; m++) {
                    dp[i][j][m] |= dp[i - 1][j][m];
                }
            }
        }
    }
    for (int m = 0; m < 501; m++) {
        if (!dp[n - 1][k][m]) continue;
        ans.insert(m);
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 501; j++) {
//            if (i][j]) cout << i << " " << j << endl;
//        }
//    }
//    for (int i : vals[4][18]) cout << i << " ";
//    cout << endl;
//    for (int i : vals[5][18]) cout << i << " ";
//    cout << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}