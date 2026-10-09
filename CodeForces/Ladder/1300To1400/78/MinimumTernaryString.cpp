//
// Created by JMKov on 4/27/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count[3] = {0, 0, 0};
    int count1[3] = {0, 0, 0};
    string out;
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - '0']++;
        if (s[i] == '2') {
            for (int j = 0; j < count[0] - count1[0]; j++) {
                out += '0';
            }
            out += '2';
            count1[0] = count[0];
            count[2]++;
        }
    }
    for (int i = 0; i < count[0] - count1[0]; i++) {
        out += '0';
    }
    for (int i = 0; i < s.size(); i++) {
        if (out[i] != '0') {
            for (int j = 0; j < count[1]; j++) {
                out.insert(out.begin() + i, '1');
            }
            break;
        }
    }
    cout << out << endl;
    return 0;
}