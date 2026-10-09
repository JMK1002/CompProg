//
// Created by JMKov on 4/4/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int letterCount[26];
    for (int i = 0; i < 26; i++) {
        letterCount[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        letterCount[s[i] - 'a']++;
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < letterCount[i]; j++) {
            ans += (char) (i + 'a');
        }
    }
    cout << ans << endl;
    return 0;
}