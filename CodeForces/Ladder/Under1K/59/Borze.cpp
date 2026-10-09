#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, output = "";
    cin >> input;
    bool dash = false;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.') {
            if (dash) {
                output += '1';
                dash = false;
            }
            else {
                output += '0';
            }
        }
        else {
            if (dash) {
                output += '2';
                dash = false;
            }
            else {
                dash = true;
            }
        }
    }
    cout << output << endl;
    return 0;
}