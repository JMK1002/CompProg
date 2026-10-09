//
// Created by JMKov on 7/16/2024.
//
#include <iostream>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int ans = 0;
    int run = 0;
    for (int i = 0; i < n; i++) run += s[i] == 'W';
    ans = run;
    for (int i = n; i < 2 * n - 1; i++) {
        run += (s[i] == 'W') - (s[i - n] == 'W');
        ans = max(ans, run);
    }
    cout << ans << endl;
    return 0;
}