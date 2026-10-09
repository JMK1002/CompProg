//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt[m];
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            cnt[j] += (s[j] == 'S');
        }
    }
//    for (int i : cnt) cout << i << " ";
//    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (n - i <= cnt[j]) cout << 'S';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}