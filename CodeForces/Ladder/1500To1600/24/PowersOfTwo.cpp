//
// Created by JMKov on 5/12/2023.
//
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    cout.precision(10);
    int pows[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j : pows) {
            count += mp[j - arr[i]];
            if (j - arr[i] == arr[i]) {
                count--;
            }
//            if (j - arr[i] == arr[i]) {
//                cout << j << " " << i << endl;
//            }
        }
    }
//    cout << count << endl;
    cout << count / 2 << endl;
    return 0;
}