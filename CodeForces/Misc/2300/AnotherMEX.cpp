#include <iostream>
using namespace std;

int n;
int arr[5005];
bool dp[5005][10000];

void solve() {
    cin > n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}