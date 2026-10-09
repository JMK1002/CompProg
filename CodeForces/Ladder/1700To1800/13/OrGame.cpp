//
// Created by JMKov on 6/10/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    long long arr[n];
    int bits[40];
    int mxCount = 0;
    for (int & bit : bits) bit = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        long long v = arr[i];
        int count = 0;
        while (v) {
            bits[count] += (v & 1);
            v = v >> 1;
            count++;
            mxCount = max(mxCount, count);
        }
    }
//    for (int i : bits) cout << i << " ";
//    cout << endl;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long v = arr[i];
        int count = 0;
        int bitOr = 0;
        while (count < mxCount) {
            bitOr += (1 << count) * (bits[count] >= (1 + (v & 1)));
            v = v >> 1;
            count++;
        }

//        long long asdfasdf = 0;
//        for (int j = 0; j < n; j++) {
//            if (j == i) continue;
//            asdfasdf = (asdfasdf | arr[j]);
//        }
        long long asdf = arr[i];
        for (int j = 0; j < k; j++) asdf *= x;
        ans = max(ans, asdf | bitOr);
//        cout << (asdf | bitOr) << endl;
    }
    cout << ans << endl;
    return 0;
}