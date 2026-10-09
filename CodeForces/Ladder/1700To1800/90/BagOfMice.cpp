//
// Created by JMKov on 7/12/2023.
//
#include <iostream>
using namespace std;

double dp[1001][1001];

int main() {
    int x, y;
    cin >> x >> y;
    cout.precision(15);
    dp[0][0] = 0;
    for (int i = 1; i <= 1000; i++) {
        dp[0][i] = 0;
        dp[i][0] = 1;
        dp[i][1] = (double) i / (i + 1);
        dp[i][2] = (double) i / (i + 2) + 2.0 / (i + 2) * 1.0 / (i + 1);
    }
    for (int w = 1; w <= 1000; w++) {
        for (int b = 3; b <= 1000; b++) {
            dp[w][b] = (double) w / (w + b) + (double) b / (w + b) * (b - 1) / (w + b - 1) *
                    ((double) (b - 2) / (w + b - 2) * dp[w][b - 3] + (double) w / (w + b - 2) * dp[w - 1][b - 2]);
        }
    }
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << dp[x][y] << endl;
    return 0;
}