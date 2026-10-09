#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // string s;
    // cin >> s;
    // for (int i = 0; i < n; i++) {
    //     int a;
    //     cin >> a;
    // }

    for (int i = 1; i < n; i += 2) {
        cout << "? " << i << " " << i + 1 << endl;
        cout.flush();
        bool a, b;
        cin >> a;
        cout << "? " << i + 1 << " " << i << endl;
        cout.flush();
        cin >> b;

        if (a != b) {
            if (i == 1) {
                cout << "? " << n << " " << i << endl;
                cout.flush();
                cin >> a;
                cout << "? " << i << " " << n << endl;
                cout.flush();
                cin >> b;
            }
            else {
                cout << "? " << 1 << " " << i << endl;
                cout.flush();
                cin >> a;
                cout << "? " << i << " " << 1 << endl;
                cout.flush();
                cin >> b;
            }
            // cout << a << " " << b << endl;
            cout << "! " << ((a != b) ? i : i + 1) << endl;
            cout.flush();
            return;
        } 
    }
    cout << "! " << n << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}