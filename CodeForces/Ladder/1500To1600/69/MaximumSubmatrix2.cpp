//
// Created by JMKov on 5/27/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int calculatePrefixArea(int x1, int y1, int x2, int y2, int *prefix[]) {
//    return prefix[x2 + 1][y2 + 1] - prefix[x2 + 1][y1] - prefix[x1][y2 + 1] + prefix[x1][y1];
//}
//
//int rectangularDfs(int x1, int y1, int x2, int y2, int n, int m, int *prefix[]) {
//    int area = (x2 - x1 + 1) * (y2 - y1 + 1);
//    if (calculatePrefixArea(x1, y1, x2, y2, prefix) != area) {
////        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
//        return -1;
//    }
//    int dir2[2][2] = {
//            {1, 0},
//            {0, 1},
//    };
//    int ret = area;
//    for (auto i : dir2) {
//        int newX = x2 + i[0];
//        int newY = y2 + i[1];
//        if (newX >= n || newY >= m) {
//            continue;
//        }
////        if (x1 == 1 && y1 == 0 && newX == 1 && newY == 1) cout << calculatePrefixArea(x1, y1, newX, newY) << " " << area << endl;
//        area = (newX - x1 + 1) * (newY - y1 + 1);
//        if (calculatePrefixArea(x1, y1, newX, newY, prefix) == area) {
//            ret = max(ret, rectangularDfs(x1, y1, newX, newY, n, m, prefix));
//        }
//    }
//    return ret;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    bool arr[n][m];
//    int *prefix[n + 1];
//    for (int i = 0; i <= n; i++) prefix[i] = new int[m + 1];
//    // reading inputs
//    for (int i = 0; i < n; i++) {
//        string s;
//        cin >> s;
////        cout << s << endl;
//        for (int j = 0; j < m; j++) {
//            arr[i][j] = (s[j] == '1');
//        }
//    }
//    // making 2d prefix matrix
//    for (int i = 0; i <= n; i++) prefix[i][0] = 0;
//    for (int i = 0; i <= m; i++) prefix[0][i] = 0;
//    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) prefix[i][j] = arr[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
//
//    int ans = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (arr[i][j] == 0) {
////                explored[i][j] = true;
//            }
//            else {
//                ans = max(rectangularDfs(i, j, i, j, n, m, (prefix)), ans);
//            }
//        }
//    }
////    for (int i = 0; i <= n; i++) {
////        for (int j = 0; j <= m; j++) {
////            cout << prefix[i][j] << " ";
////        }
////        cout << endl;
////    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (arr[i][j]) {
//                cout << 1;
//            }
//            else {
//                cout << " ";
//            }
//        }
//        cout << endl;
//    }
//    cout << ans << endl;
//    return 0;
//}

int main() {
    istream::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string arr[n];
    int right[n][m];
    // reading inputs
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        right[i][m - 1] = arr[i][m - 1] - '0';
        for (int j = m - 2; j >= 0; j--) {
            right[i][j] = (arr[i][j] - '0') * (right[i][j + 1] + 1);
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) cout << right[i][j] << " ";
//        cout << endl;
//    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> sorted(n);
        for (int j = 0; j < n; j++) {
            sorted[j] = right[j][i];
        }
        sort(sorted.begin(), sorted.end());
//        for (int x : sorted) cout << x << " ";
//        cout << endl;
        for (int j = 0; j < n; j++) {
            ans = max(ans, sorted[j] * (n - j));
        }
    }
    cout << ans << endl;
    return 0;
}