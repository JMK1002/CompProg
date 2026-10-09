//
// Created by JMKov on 5/31/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (s[i - 1] == '.' && s[i] == '.');
    }
    s = "a" + s + "a";
    while (m--) {
        int v;
        char c;
        cin >> v >> c;
        // if different
        if (c == '.' && s[v] == '.' || c != '.' && s[v] != '.') {
            cout << ans << endl;
            s[v] = c;
            continue;
        }
        s[v] = c;
        int count = ((s[v - 1] == '.') + (s[v + 1] == '.'));
//        cout << count << " SDF" << endl;
        if (c == '.') {
            ans += count;
        }
        else {
            ans -= count;
        }
        cout << ans << endl;
    }
    return 0;
}