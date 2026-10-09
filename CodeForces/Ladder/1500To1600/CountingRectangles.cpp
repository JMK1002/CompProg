//
// Created by JMKov on 6/23/2023.
//
#include <iostream>
#include <vector>
using namespace std;

long long dp[1010][1010];
long long count[1010][1010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (auto & i : dp) {
            for (long long & j : i) {
                j = 0;
            }
        }
        for (auto & i : count) {
            for (long long & j : i) {
                j = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            count[h][w] += h * w;
        }
        for (int i = 1; i < 1010; i++) {
            for (int j = 1; j < 1010; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + count[i][j];
            }
        }
        for (int i = 0; i < q; i++) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            h1++; w1++; h2--; w2--;
            cout << dp[h2][w2] - dp[max(0, h1 - 1)][w2] - dp[h2][max(0, w1 - 1)] + dp[max(0, h1 - 1)][max(0, w1 - 1)] << endl;
        }
//        for (int i = 0; i < 50; i++) {
//            for (int j = 0; j < 50; j++) {
//                cout << count[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl << endl;
//        for (int i = 0; i < 50; i++) {
//            for (int j = 0; j < 50; j++) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
    }
    return 0;
}
//dp[i][j] is the input for hs = 0 ws = 0 hb = i wb = j
