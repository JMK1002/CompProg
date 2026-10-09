//
// Created by JMKov on 6/7/2023.
//
#include <iostream>
using namespace std;

bool greaterString(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) {
            return true;
        }
        else if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}

string increment(string s1, int index) {
    string v = s1;
    while (index >= 0 && v[index] == '9') {
        v[index] = '0';
        index--;
    }
    if (index < 0) {
        v = "1" + v;
    }
    else {
        v[index] += 1;
    }
//    cout << v << endl;
    return v;
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string nw = s;
    for (int i = 0; i < n - k; i++) {
        nw[i + k] = nw[i];
    }
    if (!greaterString(nw, s)) {
        nw = increment(nw, k - 1);
    }
    for (int i = 0; i < n - k; i++) {
        nw[i + k] = nw[i];
    }
    cout << nw.size() << endl;
    cout << nw << endl;
    return 0;
}