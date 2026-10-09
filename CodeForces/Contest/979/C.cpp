#include <iostream>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = "1" + s + "1";
    for (int i = 1; i < n + 2; i++) {
        if (s[i] == '1' && s[i - 1] == '1') {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}