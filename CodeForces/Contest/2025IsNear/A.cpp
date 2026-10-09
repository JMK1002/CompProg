#include <iostream>
using namespace std;

int arr[4000];

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool ans = false;
        for (int i = 1; i < n; i++) {
            if (min(arr[i], arr[i - 1]) * 2 > max(arr[i], arr[i - 1])) ans = true;
        }
        cout << ((ans) ? "YES" : "NO") << endl;
    }
    return 0;
}