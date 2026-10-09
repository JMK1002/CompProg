//
// Created by JMKov on 3/24/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> pows(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> pows[i];
        mx = max(pows[i], mx);
    }

    int a = 0;
    int inARow = 0;
    for (int i = 0; i < n; i++) {
        if (a == i) {
            i++;
        }
        if (pows[a] > pows[i]) {
            inARow++;
        }
        else {
            a = i;
            inARow = 1;
        }

        if (inARow >= k || pows[a] == mx) {
            cout << pows[a] << endl;
            return 0;
        }
    }
    return 0;
}