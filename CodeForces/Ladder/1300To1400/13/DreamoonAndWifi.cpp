//
// Created by JMKov on 4/5/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> unknowns(0);
    cout.precision(100);
    int ans = 0;
    for (int i = 0; i < s2.size(); i++) {
        char c = s2[i];
        if (c == '?') {
            unknowns.insert(unknowns.end(), i);
        }
    }
    int target = 0;
    int actual = 0;
    for (char c : s1) {
        target += (c == '+' ? 1 : -1);
    }
    for (char c : s2) {
        actual += (c == '+' ? 1 : -1);
        actual += (c == '?');
    }
//    cout << actual << endl;
    for (int i = 0; i < pow(2, unknowns.size()); i++) {
        int current = i;
        int currentSum = actual;
        for (int j = 0; j < unknowns.size(); j++) {
//            cout << current << "SDF" << endl;
            currentSum += ((current & 1) == 1) ? -1 : 1;
            current = current >> 1;
        }
//        cout << currentSum << endl;
//        cout << endl;
        if (currentSum == target) {
            ans++;
        }
    }
    cout << (long double) ans / pow(2, unknowns.size()) << endl;
    return 0;
}