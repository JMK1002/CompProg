//
// Created by JMKov on 8/4/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int arr[4];
        for (int i = 0; i < 4; i++) arr[i] = 0;
        for (int i = 0; i < n * 4; i++) {
            if (s[i] == '?') continue;
            arr[s[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) ans += min(n, arr[i]);
        cout << ans << endl;
    }
    return 0;
}