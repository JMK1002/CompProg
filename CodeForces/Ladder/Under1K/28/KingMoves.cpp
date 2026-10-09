#include <string>
#include <iostream>
using namespace std;

int main() {
    string p;
    cin >> p;
    
    bool a, b, c, d;
    a = p[0] == 'a';
    b = p[0] == 'h';
    c = p[1] == '1';
    d = p[1] == '8';

    

    cout << 8 - ((a || b) * 3 + (c || d) * 3 - ((a || b) && (c || d))) << endl;
}