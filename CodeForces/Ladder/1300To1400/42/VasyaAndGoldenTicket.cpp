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
    int dig[n];
    int prefix[n + 1];
    for (int i = 0; i < n; i++) {
        dig[i] = s[i] - '0';
    }
    prefix[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        prefix[i] = prefix[i - 1] + dig[i - 1];
//        cout << prefix[i] << endl;
    }
    int sum = prefix[n];
    if (sum == 0) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i < sum; i++) {
        if (sum % i != 0) {
            continue;
        }
        int lastDivide = 0;
        bool works = true;
        for (int j = 1; j < n + 1; j++) {
            if (prefix[j] - prefix[lastDivide] == i) {
                lastDivide = j;
            }
            else if (prefix[j] - prefix[lastDivide] > i) {
                works = false;
                break;
            }
        }
//        cout << lastDivide << endl;
//        cout << i << endl;
//        works = works && (prefix[n] - prefix[lastDivide] == i || lastDivide == n);
        if (works) {
//            cout << i << endl;
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}