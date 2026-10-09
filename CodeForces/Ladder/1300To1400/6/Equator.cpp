//
// Created by JMKov on 4/3/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    long long currentSum = 0;
    for (int i = 0; i < n; i++) {
        currentSum += a[i];
        if (currentSum >= sum / 2 + (sum % 2 == 1)) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}