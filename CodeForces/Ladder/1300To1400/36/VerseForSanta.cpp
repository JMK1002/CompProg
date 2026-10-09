//
// Created by JMKov on 4/13/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        long long prefix[n];
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        prefix[0] = arr[0];
        int end = 2;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
            if (prefix[i] <= s) {
                end = i + 2;
            }
        }
        if (end >= n + 1) {
            cout << 0 << endl;
//            cout << "SDFDSF" << endl;
            continue;
        }
//        cout << end << " end" << endl;
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < end; i++) {
            int target = s + arr[i];
            int low = 0;
            int high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (prefix[mid] == target) {
                    low = mid;
                    break;
                }
                else if (prefix[mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            low -= (prefix[low] > target);
            if (low > mx) {
                mx = low;
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}