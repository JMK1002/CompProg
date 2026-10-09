//
// Created by JMKov on 4/24/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int m;
    cin >> s >> m;
    bool pre[s.size()];
    for (int i = 0; i < s.size(); i++) {
        pre[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        a--;
        pre[a] = !pre[a];
    }
    bool a = false;
    for (int i = 0; i < s.size() / 2; i++) {
        if (pre[i]) {
            a = !a;
        }
        if (a) {
            char c = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = c;
        }
    }
    cout << s << endl;
    return 0;
}