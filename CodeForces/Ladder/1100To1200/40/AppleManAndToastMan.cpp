//
// Created by JMKov on 3/20/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        sum += array[i];
    }

    sort(array.begin(), array.end());

    if (n != 1) {
        array[n - 2] += array[n - 1];
    }
    else {
        cout << array[0] << endl;
        return 0;
    }
    long long ans = sum;
    long long removed = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += sum - removed;
        removed += array[i];
    }
    cout << ans << endl;
    return 0;
}