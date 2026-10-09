//
// Created by JMKov on 5/10/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double val = n / k * (k - 1);
    int asdf = floor(val);
    bool works = false;
    for (int i = asdf; !works; i++) {
        int v = i;
        int s = 0;
        while (v != 0) {
//            cout << v << " ";
            s += v;
            v /= k;
        }
        works = (s >= n);
        if (works) {
            cout << i << endl;
        }
    }
    return 0;
}