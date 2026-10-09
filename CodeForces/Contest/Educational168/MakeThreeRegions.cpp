//
// Created by JMKov on 7/30/2024.
//
#include <iostream>
using namespace std;

int n;
string arr[2];

void solve() {
    cin >> n >> arr[0] >> arr[1];
    arr[0] = 'x' + arr[0] + 'x';
    arr[1] = 'x' + arr[1] + 'x';
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[j][i] == '.' && arr[j][i + 1] == '.' && arr[j][i - 1] == '.' && arr[1 - j][i + 1] == 'x' &&
                arr[1 - j][i - 1] == 'x' && arr[1 - j][i] == '.') {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}