//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cnt[26];
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 0; i < s.length(); i++) {
        cnt[s[i] - 'A']++;
    }
    int asdf = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) asdf++;
    }
    if (asdf > 1 || (asdf == 1 && s.length() % 2 == 0)) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) ans += ('A' + i);
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) ans += (i + 'A');
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    if (s.size() % 2 == 1) ans += rev.substr(1);
    else ans += rev;
    cout << ans << endl;
    return 0;
}