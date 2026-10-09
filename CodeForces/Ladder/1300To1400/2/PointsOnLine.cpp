//
// Created by JMKov on 4/2/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int a[n];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int low = 0;
        int high = n;
        int target = a[i] + d;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] == target) {
                low = mid + 1;
                break;
            }
            else if (a[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        low -= (a[low] > target);
        low -= (low == n);
//        cout << low << endl;
//        cout << max(0, (low - i - 1)) * (low - i) / 2 << endl;
        ans += (long long) max(0, (low - i - 1)) * (long long) (low - i) / 2;
    }
    cout << ans << endl;
    return 0;
}