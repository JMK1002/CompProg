//
// Created by JMKov on 8/8/2023.
//
#include <iostream>
using namespace std;

int md(int a) {
    if (a < 0) a += 3;
    else a %= 3;
    return a;
}

int main() {
    string s;
    cin >> s;
    int sum = 0;
    int mdCnt[3] = {0, 0, 0};
    for (char c : s) {
        sum += c - '0';
        mdCnt[md(c - '0')]++;
    }
    sum %= 3;
    if (sum == 0) {
        cout << s << endl;
        return 0;
    }
    if (sum == 1) {
        int r2 = 0;
        int r1 = 0;
        if (mdCnt[1] == 1 && md(s[0] - '0') == 1) {
            r1++;
            while (r1 < s.size() && s[r1] == '0') r1++;
        }
        else if (mdCnt[1] >= 1) {
            r1 = 1;
        }
        else if (mdCnt[1] == 0) {
            r1 = INT32_MAX;
        }
        if (mdCnt[2] >= 2) {
            r2 = 2;
        }
        else {
            r2 = INT32_MAX;
        }
        if (r1 == INT32_MAX && r2 == INT32_MAX) {
            cout << -1 << endl;
            return 0;
        }
        if (r1 < r2) {
            for (int i = s.size() - 1; i >= 0; i--) {
                if (md(s[i]) == sum) {
                    s.erase(s.begin() + i);
                    break;
                }
            }
            while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
            if (s.empty()) cout << -1 << endl;
            else cout << s << endl;
        }
        else {
            int cnt = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (md(s[i]) == 2) {
                    s.erase(s.begin() + i);
                    cnt++;
                    if (cnt == 2) break;
                }
            }
            while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
            if (s.empty()) cout << -1 << endl;
            else cout << s << endl;
        }
        return 0;
    }
    else {
        int r2 = 0;
        int r1 = 0;
        if (mdCnt[2] == 1 && md(s[0] - '0') == 2) {
            r2++;
            while (r2 < s.size() && s[r2] == '0') r2++;
        }
        else if (mdCnt[2] >= 1) {
            r2 = 1;
        }
        else if (mdCnt[2] == 0) {
            r2 = INT32_MAX;
        }
        if (mdCnt[1] >= 2) {
            r1 = 2;
        }
        else {
            r1 = INT32_MAX;
        }
        if (r1 == INT32_MAX && r2 == INT32_MAX) {
            cout << -1 << endl;
            return 0;
        }
        if (r1 < r2) {
            int cnt = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (md(s[i]) == 1) {
                    s.erase(s.begin() + i);
                    cnt++;
                    if (cnt == 2) break;
                }
            }
            while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
            if (s.empty()) cout << -1 << endl;
            else cout << s << endl;
        }
        else {
            for (int i = s.size() - 1; i >= 0; i--) {
                if (md(s[i]) == sum) {
                    s.erase(s.begin() + i);
                    break;
                }
            }
            while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
            if (s.empty()) cout << -1 << endl;
            else cout << s << endl;
        }
        return 0;
    }
    return 0;
}