//
// Created by JMKov on 5/19/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int leftmost[n];
    int rightmost[n];
    for (int i = 0; i < n; i++) {
        leftmost[i] = 0;
        rightmost[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; i - j >= 0 && i + j < n; j++) {
            if (s[i - j] == s[i + j]) {
                leftmost[i - j]++;
                rightmost[i + j]++;
            }
            else {
                break;
            }
        }
    }
    // 1 1 2 1 2 1 1
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
            if (s[i - j] == s[i + j + 1]) {
                leftmost[i - j]++;
                rightmost[i + j + 1]++;
            }
            else {
                break;
            }
        }
    }
    long long pre[n];
    pre[n - 1] = leftmost[n - 1];
    for (int i = n - 2; i >= 0; i--) pre[i] = leftmost[i] + pre[i + 1];
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += rightmost[i] * pre[i + 1];
    }
//    for (int i = 0; i < n; i++) {
//        cout << rightmost[i] << " " << leftmost[i] << endl;
//    }
    cout << ans << endl;
    return 0;
}