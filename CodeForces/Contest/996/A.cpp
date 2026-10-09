#include <iostream>
using namespace std;

int main() { 
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (abs(a - b) % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}