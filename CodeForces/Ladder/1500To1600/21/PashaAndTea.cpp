//
// Created by JMKov on 5/11/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    double w;
    int n;
    cin >> n >> w;
    cout.precision(10);
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << 3 * n * min((double) arr[0], min(w / 3 / n, (double) arr[n] / 2));
    return 0;
}