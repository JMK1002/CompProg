//
// Created by JMKov on 4/16/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;
    cin >> n >> s;
    int deleted = 0;
    for (int i = 0; i < n; i++) {
        if (s[i - deleted] == s[i + 1 - deleted]) {
            s.erase(s.begin() + i + 1 - deleted);
            deleted++;
        }
        else {
            i++;
        }
    }
    if (s.size() % 2 == 1) {
        s.erase(s.begin() + s.size() - 1);
        deleted++;
    }
    cout << deleted << endl << s << endl;
    return 0;
}