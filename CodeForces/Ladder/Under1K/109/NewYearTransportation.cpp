#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int portals[n - 1];
    int pos = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> portals[i];
    }
    while (pos < n - 1) {
        if (pos == t - 1) {
            cout << "YES" << endl;
            return 0;
        }
        pos += portals[pos];
    }
    if (pos == t - 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}