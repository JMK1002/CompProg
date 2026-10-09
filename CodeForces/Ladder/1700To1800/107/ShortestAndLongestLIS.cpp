//
// Created by JMKov on 7/17/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int ans[200010];

void solve(int n, string s) {
    int lb = 0;
    int pos = 0;
    int count = 0;
    while ((pos + count) < n - 1 && s[pos + count] == '>') count++;
    count++;
    int c = count;
    for (int i = pos; count >= 0; i++, count--) {
        ans[i] = lb + count;
    }
    pos += c;
    lb += c;
//        cout << pos << " " << lb << endl;
    while (pos < n) {
        if (s[pos] == '<') {
            ans[pos] = lb + 1;
            lb++; pos++;
            continue;
        }
        count = 1;
        while ((pos + count) < n && s[pos + count - 1] == '>') count++;
        c = count;
        for (int i = pos; count >= 0; i++, count--) {
            ans[i] = lb + count;
        }
        pos += c;
        lb += c;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string h = s;
        for (int i = 0; i < n - 1; i++) {
            h[i] = (s[n - i - 2] == '<') ? '>' : '<';
        }
//        cout << h << endl;
        solve(n, h);
        reverse(ans, ans + n);
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
        solve(n, s);
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}