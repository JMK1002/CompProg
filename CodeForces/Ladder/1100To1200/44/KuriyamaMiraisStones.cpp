//
// Created by JMKov on 3/22/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> sortedNums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    int m;
    cin >> m;
    long long prefixUnsorted[n + 1] = { 0 };
    long long prefixSorted[n + 1] = { 0 };
    for (int i = 1; i < n + 1; i++) {
        prefixSorted[i] = sortedNums[i - 1] + prefixSorted[i - 1];
        prefixUnsorted[i] = nums[i - 1] + prefixUnsorted[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << prefixUnsorted[r] - prefixUnsorted[l - 1] << endl;
        }
        else {
            cout << prefixSorted[r] - prefixSorted[l - 1] << endl;
        }
    }
    return 0;
}