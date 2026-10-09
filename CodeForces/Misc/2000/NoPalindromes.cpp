//
// Created by JMKov on 5/14/2024.
//
#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) {
            cout << "YES" << endl << 1 << endl << s << endl;
            return;
        }
    }
    int cnt = -1;
    for (int i = 1; i < n - 2; i++) {
        if (s[0] != s[i] && s[i + 1] != s[n - 1]) {
            cout << "YES" << endl << 2 << endl << s.substr(0, i + 1) << " " << s.substr(i + 1) << endl;
            return;
        }
        else if (s[0] != s[i]) {
            cnt = i;
            break;
        }
    }

    if (cnt == -1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = cnt + 1; i < n; i++) {
        if (s[i] != s[n - (i - cnt)]) {
            cout << "YES" << endl << 2 << endl << s.substr(0, cnt + 1) << " " << s.substr(cnt + 1) << endl;
            return;
        }
    }

    if (!(cnt == 1 || cnt == (n + 1) / 2 - 1)) {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s.substr(0, cnt + 2) << " " << s.substr(cnt + 2) << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}