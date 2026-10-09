//
// Created by JMKov on 4/14/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

bool binSearch(long long t, std::vector<int> arr, int low, int high);

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (binSearch(x, arr, 0, n - 1)) {
            cout << 1 << endl;
            continue;
        }
        long long s1 = x / arr[n - 1] / 2 * arr[n - 1];
        long long s2 = x / arr[n - 1] / 2 * arr[n - 1];
        ans += x / arr[n - 1] / 2 * 2;
        while (s1 + s2 < x) {
            s1 += arr[n - 1];
            ans++;
            if (s1 + s2 >= x) {
                break;
            }
            s2 += arr[n - 1];
            ans++;
        }
        while (s2 + x < s1) {
            s2 += arr[n - 1];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

bool binSearch(long long t, vector<int> arr, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == t) {
            return true;
        }
        else if (arr[mid] < t) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}
