//
// Created by JMKov on 3/28/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        int count = 1;
        if (s1[0] != s2[0]) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 1; i < s2.size(); i++) {
            if (s2[i] == s1[count]) {
                count++;
            }
            else if (s1[count - 1] != s2[i]) {
                count = -1; // making it always print "NO"
                break;
            }
        }
        if (count == s1.size()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}