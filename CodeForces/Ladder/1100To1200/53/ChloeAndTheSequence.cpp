//
// Created by JMKov on 3/24/2023.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i < 51; i++) {
        if (k % (long long) pow(2, i) == (long long) pow(2, i - 1)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}