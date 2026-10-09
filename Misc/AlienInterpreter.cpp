//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> strings;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            strings.push_back(s.substr(last + 1,  i - last - 1));
            last = i;
        }
    }
    strings.push_back(s.substr(last + 1));
//    for (string a : strings) cout << a << " ";
//    cout << endl;
    string ans;
    for (int i = 1; i < strings.size(); i += 2) {
        cout << strings[i].substr(0, strings[i].size() - 3);
        cout << strings[i - 1];
        cout << " ";
    }
    return 0;
}