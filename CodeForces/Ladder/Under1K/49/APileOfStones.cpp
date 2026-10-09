#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    int n;
    string operations;
    cin >> n >> operations;
    int delta = 0;
    int lowest = 0;
    for (char c : operations) {
        if (c == '+') {
            delta++;
        }
        else {
            delta--;
        }
        if (lowest >= delta) {
            lowest = delta;
        }
    }
    cout << delta - lowest << endl;
    return 0;
}