#include <iostream>
#include <string>
using namespace std;

int main() {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string s, output = "";
    char dirChar;
    cin >> dirChar >> s;
    int dir = (dirChar == 'L') ? 1 : -1;
    for (char c : s) {
        for (int i = 0; i < keyboard.size(); i++) {
            if (c == keyboard[i]) {
                output += keyboard[i + dir];
            }
        } 
    }
    cout << output << endl;
    return 0;
}