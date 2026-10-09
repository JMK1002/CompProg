//
// Created by JMKov on 4/21/2023.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printTree(vector<vector<int>> a) {
    for (auto x : a) {
        if (x.size() > 100) {
            continue;
        }
        for (auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    vector<int> a((long long) pow(2, 19), 0);
    while (t--) {
        char c;
        string s;
        cin >> c >> s;
        if (c == '?') {
            unsigned long long val = pow(2, s.size());
            for (int i = 0; i < s.size(); i++) {
                val += ((s[i] - '0') % 2) * (unsigned long long) pow(2, s.size() - i - 1);
            }
            cout << a[val] << endl;
            continue;
        }

        while (s.size() > 0 && (s[0] - '0') % 2 == 0) {
            s.erase(s.begin());
        }

        unsigned long long index = 0;
        for (int i = 0; i < s.size(); i++) {
            index += ((s[i] - '0') % 2) * (unsigned long long) pow(2, s.size() - i - 1);
        }
//        cout << s << " " << index << endl;
        if (c == '+') {
            for (int i = s.size(); i < 19; i++) {
                a[index + (unsigned long long) pow(2, i)]++;
            }
        }
        else {
            for (int i = s.size(); i < 19; i++) {
                a[index + (unsigned long long) pow(2, i)]--;
            }
        }

    }
    return 0;
}