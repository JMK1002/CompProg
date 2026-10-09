//
// Created by JMKov on 5/25/2023.
//
#include <iostream>
using namespace std;
const int big = 1e+5;
int children[big];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        children[a]++;
        children[b]++;
    }
    for (int i : children) {
        if (i == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}