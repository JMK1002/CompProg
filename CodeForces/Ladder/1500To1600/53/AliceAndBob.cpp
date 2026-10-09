//
// Created by JMKov on 5/21/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int a;
    cin >> a;
    int mx = a;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        a = __gcd(a, arr[i]);
        mx = max(mx, arr[i]);
    }
//    cout << a << " " << mx << endl;
    cout << (((mx / a -  n) % 2 == 0) ? "Bob" : "Alice") << endl;
    return 0;
}