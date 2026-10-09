//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (long long) (n) * (n + 1) / 2 - sum << endl;
    return 0;
}