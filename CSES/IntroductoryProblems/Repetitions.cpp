//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char prev = 'o';
    int cnt = 0;
    int ans = (s.size() != 0);
    for (char c : s) {
        if (c == prev) {
            cnt++;
            ans = max(ans, cnt);
        }
        else {
            cnt = 1;
            prev = c;
        }
    }
    cout << ans << endl;
    return 0;
}