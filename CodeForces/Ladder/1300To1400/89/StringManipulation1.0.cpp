//
// Created by JMKov on 5/1/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n;
    string s;
    cin >> k >> s >> n;
    string asdf = s;
    for (int i = 1; i < k; i++) {
        s += asdf;
    }
    vector<int> positions[26];
    for (int i = 0; i < s.size(); i++) {
        positions[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        s[positions[c - 'a'][p]] = ' ';
        positions[c - 'a'].erase(positions[c - 'a'].begin() + p);
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
            i--;
        }
    }
    cout << s << endl;
    return 0;
}