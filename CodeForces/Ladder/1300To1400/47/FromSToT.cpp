//
// Created by JMKov on 4/17/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t, p;
        cin >> s >> t >> p;
        int ptr = 0;
        int charCount[26];
        bool ans = s.size() <= p.size();
        for (int i = 0; i < 26; i++) {
            charCount[i] = 0;
        }
        for (int i = 0; i < p.size(); i++) {
            charCount[p[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (ptr != s.size() && t[i] == s[ptr]) {
                ptr++;
            }
            else {
                charCount[t[i] - 'a']--;
            }
        }
        if (s.size() != ptr) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < 26; i++) {
//            cout << charCount[i] << " ";
            if (charCount[i] < 0) {
                ans = false;
            }
        }
//        cout << endl;
        cout << ((ans) ? "YES" : "NO") << endl;
    }
    return 0;
}