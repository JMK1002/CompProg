#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s = "";
        if (n % 2 == 1) {
            n -= 3;
            s = "7";
        }
        for (int i = 0; i < n / 2; i++) {
            s += "1";
        }
        cout << s << endl;
    }
    return 0;
}