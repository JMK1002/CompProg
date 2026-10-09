//
// Created by JMKov on 3/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mx = 1;
    int consecutive = 1;
    long long last;
    cin >> last;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (last * 2 >= a) {
            consecutive++;
        }
        else {
            consecutive = 1;
        }
        mx = max(consecutive, mx);
        last = a;
    }
    cout << mx << endl;
    return 0;
}