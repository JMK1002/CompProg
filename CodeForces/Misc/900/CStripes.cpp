#include <iostream>
#include <string>
using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int x = 0; x < cases; x++) {
        string input[8];
        bool output = false;
        for (int i = 0; i < 8; i++) {
            cin >> input[i];
            bool fullRow = true;
            for (int j = 0; j < 8; j++) {
                if (input[i][j] != 'R') {
                    fullRow = false;
                }
            }
            output |= fullRow;
        }
        cout << ((output) ? 'R' : 'B') << "\n";
    }
    
    
    
    return 0;
}