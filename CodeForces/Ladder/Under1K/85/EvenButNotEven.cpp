#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        string output = "";
        cin >> n >> s;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 1) {
                output += s[i];
            }
            if (output.size() == 2) {
                cout << output << endl;
                break;
            }
        }
        if (output.size() < 2) {
            cout << -1 << endl;
        }
    }
    return 0;
}