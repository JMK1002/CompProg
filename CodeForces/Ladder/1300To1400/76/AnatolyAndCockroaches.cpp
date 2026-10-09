//
// Created by JMKov on 4/27/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int count[2][2] = {0, 0, 0, 0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if ((j + i) % 2 == 0 && s[j] == 'r') {
                count[i][0]++;
            }
            else if ((j + i) % 2 == 1 && s[j] == 'b') {
                count[i][1]++;
            }
        }
    }
    cout << min(max(count[0][0], count[0][1]), max(count[1][0], count[1][1])) << endl;
    return 0;
}