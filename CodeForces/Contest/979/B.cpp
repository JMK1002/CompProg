#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "0" << endl;
            continue;
        }
        cout << "1";
        for (int i = 1; i < n; i++) cout << "0";
        cout << endl;
    }
    return 0;
}