//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
using namespace std;

int n;
string s;
int charCnt[12];

void clean() {
    for (int i = 0; i < 12; i++) charCnt[i] = 0;
    s.clear();
    n = 0;
}

int conv(int ind) {
    return (s[ind] - '0') * 10 + s[ind + 1] - '0';
}

void solve() {
    cin >> n >> s;
    if (n == 2) {
        cout << conv(0) << endl;
        clean();
        return;
    }
    else if (n == 3) {
        int ans = 2000000000;
        ans = min(s[0] - '0' + conv(1), (s[0] - '0') * conv(1));
        ans = min(ans, min(s[2] - '0' + conv(0), (s[2] - '0') * conv(0)));
        cout << ans << endl;
        clean();
        return;
    }

    for (int i = 0; i < n; i++) {
        charCnt[s[i] - '0']++;
    }
    if (charCnt[0] != 0) {
        cout << 0 << endl;
        clean();
        return;
    }
    int sum = 0;
    for (int i = 2; i < 11; i++) {
        sum += i * charCnt[i];
    }

    int ans = 2000000000;
    for (int i = 0; i < n - 1; i++) {
        int val = sum;
        if (s[i] != '1') val -= (s[i] - '0');
        if (s[i + 1] != '1') val -= (s[i + 1] - '0');
        val += conv(i);
        ans = min(ans, val);
    }
    cout << ans << endl;
    clean();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}