#include <iostream>
using namespace std;

const int MAXN = 1000000;

int n;
int arr[MAXN];
int dp[MAXN];
int mx[MAXN];
bool works[MAXN];

void solve() {
    // * instantiate array dp[i] which is the max amount of tests in suffix starting at i
    // * also instantiate works[i] which is true if ends at appropriate end
    // ! If works[i + 1] && dp[i + 1] == arr[i]: 0
    // ! Else if works[i + 1] or dp[i + 1] >= arr[i] or mx[i + 1] >= arr[i] ?
    //      ? (can modify an element s.t. works with arr[i] tests) : 1
    //      * Need to somehow calculate array mx[i] which is the maximum amount tests
    //      * After changing AT MOST one element
    //      * mx[i] = 1 + max(mx[i + arr[i] + 1], dp[j]) given j > i && works[j] is true
    // ! Else : 2

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    works[n] = true;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i + arr[i] + 1]; // always in bounds
        works[i] = works[i + arr[i] + 1];
    }
    int run = 0;
    for (int i = n - 1; i >= 0; i--) {
        mx[i] = 1 + max(mx[i + arr[i] + 1], run);
        if (works[i]) run = max(run, dp[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (works[i + 1] && dp[i + 1] == arr[i]) cout << 0 << " ";
        else if (works[i + 1] || dp[i + 1] >= arr[i] || mx[i + 1] >= arr[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        dp[i] = 0;
        mx[i] = 0;
        works[i] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}