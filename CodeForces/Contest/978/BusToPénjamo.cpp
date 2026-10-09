#include <iostream>
using namespace std;

int arr[1000];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            cnt += (arr[i] % 2);
            ans += arr[i] / 2;
        }
        if (cnt <= r - ans) {
            cout << cnt + ans * 2 << endl;
        }
        else {
            cout << (r - ans) - (cnt - (r - ans)) + ans * 2 << endl;
        }
    }
    return 0;
}