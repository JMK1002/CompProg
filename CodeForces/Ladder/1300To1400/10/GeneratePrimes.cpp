//
// Created by JMKov on 4/4/2023.
//
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> generatePrimes(int n) {
    int list[n - 1];
    for (int i = 0; i < n - 1; i++) {
        list[i] = i + 2;
    }
    for (int i = 0; list[i] < sqrt(n); i++) {
        int val = list[i];
        if (val == -1) {
            continue;
        }
        for (int j = i + val; j < n; j += val) {
            list[j] = -1;
        }
    }
    vector<int> out(0);
    for (int i : list) {
        if (i != -1) {
            out.insert(out.end(), i);
        }
    }
    return out;
}

int main() {
//    vector<int> a = generatePrimes(100003);
//    int maxdist = 0;
//    for (int i = 1; i < a.size(); i++) {
//        maxdist = max(maxdist, a[i] - a[i - 1]);
//    }
    cout << 500 << " " << 500 << endl;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            cout << 1000 << " ";
        }
    }
    return 0;
}