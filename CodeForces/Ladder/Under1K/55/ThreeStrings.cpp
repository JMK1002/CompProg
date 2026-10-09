#include <string>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        bool aaa = true;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != c[i] && b[i] != c[i]) {
                aaa = false;
                break;
            }
        }
        cout << ((aaa) ? "YES" : "NO") << endl;
    }
    return 0;
}