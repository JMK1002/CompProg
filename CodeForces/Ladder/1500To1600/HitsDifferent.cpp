//
// Created by JMKov on 6/13/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long * vals = new long long[1002000];
    vals[1] = 1;
    long long prev = 1;
    for (long long i = 1; i < 1415; i++) {
        vals[prev + 1] = vals[prev - i + 1] + (prev + 1) * (prev + 1);
        vals[prev + i + 1] = vals[prev] + (prev + i + 1) * (prev + i + 1);
//        cout << prev + 1 << " " << vals[prev + 1] << " " << prev + i + 1 << " " << vals[prev + i + 1] << endl;
        prev += i + 1;
    }
    prev = 1;
    for (long long i = 1; i < 1415; i++) {
        vals[prev + 1] = vals[prev - i + 1] + (prev + 1) * (prev + 1);
        vals[prev + i + 1] = vals[prev] + (prev + i + 1) * (prev + i + 1);
        for (long long j = prev + 2; j < prev + i + 1; j++) {
            vals[j] = vals[j - i] + vals[j - i - 1] - vals[j - 2 * i] + j * j;
        }
        prev += i + 1;
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << vals[x] << endl;
    }
    return 0;
}