//
// Created by JMKov on 5/3/2023.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

void asdf(int i) {
    bool works[i + 1];
    for (int j = 0; j <= i; j++) {
        works[j] = false;
    }
    for (int j = 1; j <= i + 1; j++) {
        works[i / j] = true;
    }
    for (int j = 0; j <= i; j++) {
        if (works[j]) {
            cout << j << " ";
        }
//        else {
//            cout << "   ";
//        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int upTo = (int) sqrt(n);
        vector<int> out(upTo + 1);
        iota(out.begin(), out.end(), 0);
        int a = 0;
        while (n / (a + 1) > upTo) {
            a++;
            if (out[out.size() - 1] == n / a) {
                continue;
            }
            out.push_back(n / a);
        }
        sort(out.begin(), out.end());
        cout << out.size() << endl;
        for (int i : out) {
            cout << i << " ";
        }
        cout << endl;
//        asdf(n);
    }
    return 0;
}