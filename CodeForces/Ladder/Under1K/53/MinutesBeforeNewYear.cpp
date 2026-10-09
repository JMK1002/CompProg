#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int h, m;
        cin >> h >> m;
        cout << (24 - h) * 60 - m << endl;
    } 
    return 0;
}