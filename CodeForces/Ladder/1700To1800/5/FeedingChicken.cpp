//
// Created by JMKov on 6/7/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string arr[n];
        int riceCount = 0;
        char ans[n][m];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'R') {
                    riceCount++;
                }
            }
        }
        int amnt = riceCount / k;
        int color = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = m - 1; j >= 0; j--) {
                    ans[i][j] = min(color, k - 1);
                    count += (arr[i][j] == 'R');
                    if (count == amnt + (color >= (k - riceCount % k))) {
                        color++;
                        count = 0;
                    }
                }
            } else {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = min(color, k - 1);
                    count += (arr[i][j] == 'R');
                    if (count == amnt + (color >= (k - riceCount % k))) {
                        color++;
                        count = 0;
                    }
                }
//                cout << (k - riceCount % k) << endl;
            }
        }
        for (auto i: ans) {
            for (int j = 0; j < m; j++) {
                if (i[j] < 10) {
                    i[j] += '0';
                }
                else if (i[j] >= 10 && i[j] < 36) {
                    i[j] += 'a' - 10;
                }
                else {
                    i[j] += 'A' - 36;
                }
                cout << i[j];
            }
            cout << endl;
        }
//        cout << endl;
    }
    return 0;
}
// R.R
// .R.
// R.R