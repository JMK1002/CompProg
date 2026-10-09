#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b, x1 = 10000, y1 = 100000, x2 = -1, y2 = -1;
    cin >> a >> b;
    string input[a];
    for (int i = 0; i < a; i++) {
        string line;
        cin >> line;
        input[i] = line;
        for (int j = 0; j < b; j++) {
            if (line[j] == '*') {
                x1 = min(j, x1);
                y1 = min(i, y1);
                x2 = max(j, x2);
                y2 = max(i, y2);
            }
        }
    }

    for (int i = y1; i <= y2; i++) {
        cout << input[i].substr(x1, x2 + 1 - x1) << endl;
    }
}