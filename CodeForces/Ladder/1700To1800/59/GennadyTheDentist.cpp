//
// Created by JMKov on 6/30/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long *> arr(n);
    for (long long i = 0; i < n; i++) {
        arr[i] = new long long[3];
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<long long> ans;
    for (long long i = 0; i < arr.size(); i++) {
        if (arr[i][2] < 0) continue;
        long long count = 1;
        long long p = i;
        long long v = 0;
        while (count + p < arr.size()) {
            while (count + p < arr.size() && arr[count + p][2] < 0) p++;
            if (count + p >= arr.size()) break;
            arr[count + p][2] -= max((long long) 0, arr[i][0] - count + 1);
//            if (arr[count + p][2] < 0) v += arr[count + p][1];
            arr[count + p][2] -= v;
            if (arr[count + p][2] < 0) {
                v += arr[count + p][1];
            }
            count++;
        }
//        cout << endl;
        ans.push_back(i);
//        for (long long j = 0; j < n; j++) cout << arr[j][2] << " ";
//        cout << endl;
    }
    cout << ans.size() << endl;
    for (long long i : ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}
// 6
// 3 1 1
// 4 2 3
// 3 3 3
// 5 1 5
// 2 7 5
// 1 1 12

//5
//4 2 2
//4 1 -2
//5 2 0
//3 3 2
//5 1 -1

//10
//10 7 10
//3 6 1
//8 4 -2
//10 1 -3
//7 3 0
//7 2 2
//7 6 4
//3 4 8
//9 4 12
//5 2 17

// 10 1 1 3 6 7 9 13 17 22
// 1 -1 -3 0 3 5 9 13 18