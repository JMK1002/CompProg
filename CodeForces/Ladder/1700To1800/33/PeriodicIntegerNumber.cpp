//
// Created by JMKov on 6/19/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    string ans;
    cin >> n >> s;
    bool bruh = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '9') {
            bruh = false;
            break;
        }
    }
    if (s.size() % n != 0 || bruh) {
        if (bruh) s += '1';
        while (ans.size() < s.size() || ans.size() % n != 0) {
            if (ans.size() % n == 0) {
                ans += '1';
            }
            else {
                ans += '0';
            }
        }
//        cout << ans << endl;
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            ans += s[i % n];
        }
        if (ans <= s) {
            for (int i = n - 1; i < s.size(); i += n) {
                int v = i;
                while (ans[v] == '9') {
                    ans[v] = '0';
                    v--;
                }
                ans[v] += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}