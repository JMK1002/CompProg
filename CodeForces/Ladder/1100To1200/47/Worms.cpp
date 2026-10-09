//
// Created by JMKov on 3/22/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ai[n];
    int prefix[n + 1] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }
    for (int i = 1; i < n + 1; i++) {
        prefix[i] = prefix[i - 1] + ai[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        int a = 0;
        int b = n - 1;
        int ans;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (prefix[mid] <= target && target <= prefix[mid + 1]) {
                a = b + 1;
            }
            else if (prefix[mid + 1] > target) {
                b = mid - 1;
            }
            else {
                a = mid + 1;
            }
            ans = mid;
        }
        ans = (target > prefix[ans]) ?
        ans + 1 : ans;
        cout << ans << endl;
    }
    return 0;
}
// 2 9 12 16 25