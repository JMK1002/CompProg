//
// Created by JMKov on 5/1/2023.
//
#include <iostream>
#include <string>
using namespace std;

string reverse(string a) {
    for (int i = 0; i < a.size() / 2; i++) {
        char c = a[i];
        a[i] = a[a.size() - i - 1];
        a[a.size() - i - 1] = c;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        string ans = s;
        int v = 0;
        for (int i = 1; i < n; i++) {
            string asdf = s;
            string substring = s.substr(0, i);
            string out = s.substr(i, n) + ((((i + n) & 1) == 1) ? reverse(substring) : substring);
            if (ans.compare(out) > 0) {
                ans = out;
                v = i;
            }
        }
        cout << ans << endl;
        cout << v + 1 << endl;
    }
    return 0;
}
// abcde
// bcdea
// cdeba
// deabc
// edcba

// abcdef
// bcdefa
// cdefab