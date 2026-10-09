#include <iostream>
#include <string>
using namespace std;

int main() {
    int white = 0;
    int black = 0;
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            switch(c) {
                case 'q': 
                    black += 9;
                    break; 
                case 'r': 
                    black += 5;
                    break; 
                case 'b': 
                    black += 3;
                    break; 
                case 'n': 
                    black += 3;
                    break; 
                case 'p': 
                    black += 1;
                    break; 
                case 'Q': 
                    white += 9;
                    break; 
                case 'R': 
                    white += 5;
                    break; 
                case 'B': 
                    white += 3;
                    break; 
                case 'N': 
                    white += 3;
                    break; 
                case 'P': 
                    white += 1;
                    break; 
            }
        }
    }
    if (white > black) {
        cout << "White" << endl;
    }
    else if (black > white) {
        cout << "Black" << endl;
    }
    else {
        cout << "Draw" << endl;
    }
    return 0;
}