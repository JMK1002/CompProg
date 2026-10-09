#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
#include <ctime>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int dp[5001][5001][2];
int a[5001];

int main() {
    fast
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1])
            a[++l] = a[i];
    n = l;
    for (int cnt = 1; cnt <= n; cnt++) {
        int i = 1, j = cnt;
        while (j <= n) {
            if (i == j)
                dp[i][j][0] = dp[i][j][1] = 0;
            else if (a[i] != a[j]) {
                dp[i][j][1] = min(dp[i][j - 1][0], dp[i][j - 1][1]) + 1;
                dp[i][j][0] = min(dp[i + 1][j][0], dp[i + 1][j][1]) + 1;
            }
            else dp[i][j][0] = dp[i][j][1] = dp[i][j - 1][0];
            i++, j++;
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]);
    return 0;
}
