//
// Created by JMKov on 7/14/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
//    for (const string& s : arr) cout << s << endl;
    for (int i = n - 2; i >= 0; i--) {
        string s;
        bool a = true;
        for (int j = 0; j < min(arr[i].size(), arr[i + 1].size()); j++) {
            if (arr[i][j] < arr[i + 1][j]) {
                s += arr[i][j];
                a = false;
            }
            else if (arr[i][j] == arr[i + 1][j]) {
                s += arr[i][j];
            }
            else break;
        }
        if (a) arr[i] = s;
    }
//    cout << n << endl;
    for (const string& s : arr) cout << s << endl;
    return 0;
}