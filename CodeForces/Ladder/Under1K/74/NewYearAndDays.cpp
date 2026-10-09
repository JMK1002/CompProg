#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s >> s;
    if (s == "week") {
        if (n == 5 || n == 6) {
            cout << 53 << endl;
            return 0;
        }
        cout << 52 << endl;
    }
    else {
        cout << 7 * (n <= 31) + 4 * (n <= 30) + 1 * (n <= 29);
    }
    return 0;
}