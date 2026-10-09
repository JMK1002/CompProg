//
// Created by JMKov on 4/11/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int mappedVals[9];
    bool greater[9];
    for (int i = 0; i < 9; i++) {
        cin >> mappedVals[i];
        greater[i] = (mappedVals[i] >= (i + 1));
    }
    bool changeMade = false;
    for (int i = 0; i < n; i++) {
//        cout << s[i] - '1' << " " << mappedVals[s[i] - '1'] << endl;
        if (greater[s[i] - '1']) {
            changeMade = changeMade || (s[i] != mappedVals[s[i] - '1'] + '0');
            s[i] = (char) (mappedVals[s[i] - '1'] + '0');
        }
        else if (changeMade) {
            break;
        }
    }
    cout << s << endl;

    return 0;
}