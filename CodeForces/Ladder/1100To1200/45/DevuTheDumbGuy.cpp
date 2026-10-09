//
// Created by JMKov on 3/22/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unsigned long long n, x;
    cin >> n >> x;
    vector<unsigned long long> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (array[i]) * x;
        x--;
        x = max(x, (unsigned long long) 1);
    }
    cout << sum << endl;
    return 0;
}