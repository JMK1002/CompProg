//
// Created by JMKov on 5/4/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(long long a, long long b) {
    int x = 0;
    int y = 0;
    while (a % 3 == 0) {x++; a /= 3;}
    while (b % 3 == 0) {y++; b /= 3;}
    if (x == y) {
        return a < b;
    }
    return x > y;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), compare);
    for (long long i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}