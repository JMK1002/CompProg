#include <iostream>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << max(n, m) + 1 << endl;
    }
    return 0;
}