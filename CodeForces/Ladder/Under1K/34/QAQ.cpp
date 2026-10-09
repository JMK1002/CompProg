#include <string>
#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;
    int qCount = 0;
    int aCount = 0;
    string onlySpecials = "";
    int ret = 0;
    for (char c : input) {
        if (c == 'Q') {
            onlySpecials += 'Q';
        }
        if (c == 'A') {
            onlySpecials += 'A';
        }
    }

    for (int i = 0; i < onlySpecials.length(); i++) {
        if (onlySpecials[i] == 'A') {
            continue;
        }
        for (int j = i + 1; j < onlySpecials.length(); j++) {
            if (onlySpecials[j] == 'Q') {
                continue;
            }
            for (int k = j + 1; k < onlySpecials.length(); k++) {
                if (onlySpecials[k] == 'A') {
                    continue;
                }
                ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}