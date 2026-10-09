//
// Created by JMKov on 7/30/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int mx = -1;
        string ans = "";

        for (int i = 0; i <= n; i++) {
            char c = 'a';
            while ((i != 0 && c == s[i - 1]) || (i != n && c == s[i])) c++;
            s.insert(s.begin() + i, c);

            int amnt = 2;
            for (int j = 1; j <= n; j++) {
                if (s[j] == s[j - 1]) amnt += 1;
                else amnt += 2;
            }
            if (amnt > mx) {
                mx = amnt;
                ans = s;
            }
            s.erase(s.begin() + i);
        }
        cout << ans << endl;

    }
    return 0;
}