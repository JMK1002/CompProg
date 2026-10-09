//
// Created by JMKov on 6/16/2023.
//
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    multiset<int> b;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        b.insert(a);
    }
    auto ptr = b.end();
    ptr--;

    return 0;
}