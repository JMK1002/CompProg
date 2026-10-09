//
// Created by JMKov on 4/15/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string strs[6] = {
            "RGB",
            "RBG",
            "GRB",
            "GBR",
            "BRG",
            "BGR",
    };
    int accuracy[6];
    for (int i = 0; i < 6; i++) {
        accuracy[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        char c = s[i];
        for (int j = 0; j < 6; j++) {
            accuracy[j] += (strs[j][i % 3] == c);
        }
    }
    int in = 0;
    int mn = -1;
    for (int i = 0; i < 6; i++) {
//        cout << accuracy[i] << " " << strs[i] << endl;
        if (accuracy[i] > mn) {
            mn = accuracy[i];
            in = i;
        }
    }
    string out;
    for (int i = 0; i < n / 3; i++) {
        out.append(strs[in]);
    }
    out.append(strs[in].substr(0, n - n / 3 * 3));
    cout << n - mn << endl;
    cout << out << endl;
    return 0;
}