//
// Created by JMKov on 6/25/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[200010];
long long prefix[200010];

bool binSearch(int days) {
    for (int i = n - days; i >= 0; i--) {
        int length = n - i;
        int pos = i - 1;
        long long v = prefix[n - 1] - prefix[i - 1] - (length % days) * (length / days + 1) * (length / days) / 2 - (days - length % days) * (length / days) * (length / days - 1) / 2;
        if (arr[i] < length / days + (length % days != 0) - 1) {
            while (arr[i] < length / days + (length % days != 0) - 1) {
                v += length / days + (length % days != 0) - 1 - arr[i];
                i++;
            }
            if (v >= m) {
                return true;
            }
            return false;
        }
//        cout << v << " " << length << " " << days << endl;
//        for (int j = days; j > 0; j--) { // would have issues with negative numbers potentially
//            v -= (length / j) * (length / j - 1) / 2;
//            length -= (length / j);
//        }
        if (v >= m) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) prefix[i] = arr[i] + prefix[i - 1];
    int low = 1;
    int high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (binSearch(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
//    cout << low << endl;
    low += !(binSearch(low));
    if (low > n) {
        cout << -1 << endl;
        return 0;
    }
    cout << low << endl;
    return 0;
}