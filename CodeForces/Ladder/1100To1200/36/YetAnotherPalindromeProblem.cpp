#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nums[n];
        int lookup[n + 1] = { 0 };
        bool ans = false;
        cin >> nums[0];
        cin >> nums[1];
        for (int i = 2; i < n; i++) {
            cin >> nums[i];
            if (nums[i - 2] == nums[i]) {
                ans = true;
            }
        }

        if (ans) {
            cout << "YES" << endl;
            continue;
        }

        // for (int i = 0; i < n - 3; i++) {
        //     if (nums[i] == nums[i + 3] && nums[i + 1] == nums[i + 2]) {
        //         ans = true;
        //         i = n;
        //     }
        // }

        if (ans) {
            cout << "YES" << endl;
            continue;
        }

        lookup[nums[0]]++;
        for (int i = 1; i < n; i++) {
            lookup[nums[i]] += 1 - (nums[i - 1] == nums[i]);
        }
        for (int i = 0; i <= n; i++) {
            if (lookup[i] >= 2) {
                ans = true;
                i = n;
            }
        }
        cout << ((ans) ? "YES" : "NO") << endl;
    }
    return 0;
}