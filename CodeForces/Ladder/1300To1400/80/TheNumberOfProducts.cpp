//
// Created by JMKov on 4/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    long long posCount = 0;
    long long negCount = 0;
    long long pSeg = 0;
    long long nSeg = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            long long a = posCount;
            posCount = negCount;
            negCount = a;
            negCount++;
        }
        else {
            posCount++;
        }
        pSeg += posCount;
        nSeg += negCount;
    }
    cout << nSeg << " " << pSeg << endl;
    return 0;
}
// 4 2 -4 3 1 2 -4 3 2 3
// 0
// 0 0
// 1 1 1
// 1 1 1 0
// 1 1 1 0 0
// 1 1 1 0 0 0
// 0 0 0 1 1 1 1
// 0 0 0 1 1 1 1 0


// 5 -3 3 -1 1
// 0
// 1 1
// 1 1 0
// 0 0 1 1
// 0 0 1 1 0
// 7 8