//
// Created by JMKov on 4/7/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        double b;
        cin >> b;
//        double b += 0.5; // so that it always looks at the last of the same term;
        int low = 0;
        int high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[mid] <= b) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        low -= (a[low] > b);
        cout << min(n, low + 1) << " ";
    }
    return 0;
}