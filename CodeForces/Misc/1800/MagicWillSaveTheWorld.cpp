//
// Created by JMKov on 4/22/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b;
        cin >> n;
        int arr[n];
        int s = 0;
        set<int> pos;
        pos.insert(0);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }
        for (int i = 0; i < n; i++) {
            vector<int> curr;
            for (int j : pos) {
                if (j + arr[i] <= s / 2) curr.push_back(j + arr[i]);
            }
            for (int j : curr) pos.insert(j);
        }
        int ans = 1000000000;
        for (int i : pos) {
            ans = min(ans, max((i - 1) / a + 1, (s - i - 1) / b + 1));
            ans = min(ans, max((s - i - 1) / a + 1, (i - 1) / b + 1));
        }
        cout << ans << endl;
    }
    return 0;
}