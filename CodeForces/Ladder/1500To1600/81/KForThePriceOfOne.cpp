//
// Created by JMKov on 5/31/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binSearch(int arr[], int target, int low, int high, int n) {
    double actTar = target + 0.5;
    int initHigh = high;
    int initLow = low;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] > actTar) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    low += (low <= initHigh && arr[low] < actTar);
    low -= (low > initLow && arr[low - 1] > actTar);
    return low;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int prefix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];
        int ans = 0;
        for (int i = 0; i < k && i + k - 1 < n; i++) {
            int v = 0;
            int ptr = i + k - 1;
            int count = 0;
            while (ptr < n && v <= p) {
                v += arr[ptr];
                ptr += k;
                count += k;
            }
            ptr -= k;
            if (v > p) {
                v -= arr[ptr];
                ptr -= k;
                count -= k;
            }
//            cout << ptr << "SDF ";
            // ptr now stores the value of the last element added to v
            int add = 0;
            if (binSearch(prefix, p - v, 0, n - 1, n) > i) { // maybe >=
                add += i;
//                if (add + count != ptr + 1) cout << "WTF WHYYYYYYYYYY SDFDFSFS";
                if (i > 0) v += prefix[i - 1];
//                cout << prefix[ptr] << " asdf ";
                int a = binSearch(prefix, p - v + prefix[ptr] * (ptr >= 0 && ptr < n), ptr + 1, n - 1, n) - ptr - 1;
                add += a;
            }
            else {
                add += binSearch(prefix, p - v, 0, n - 1, n);
            }
//            for (int j = 0; j < i && v <= p; j++) {
//                v += arr[j];
//                count++;
//                if (v > p) {
//                    v -= arr[j];
//                    count--;
//                    break;
//                }
//            }
//            for (int j = ptr + 1; j < n && v <= p; j++) {
//                v += arr[j];
//                count++;
//                if (v > p) {
//                    v -= arr[j];
//                    count--;
//                    break;
//                }
//            }
//            cout << count << " " << add << "   ";
            count += add;
            ans = max(ans, count);
        }
        cout << ans << endl;
//        cout << endl;
    }

    return 0;
}
//1
//5 8 3
//1 2 3 6 7

//1
//5 2 3
//1 2 3 9 10