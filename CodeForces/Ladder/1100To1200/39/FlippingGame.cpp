//
// Created by JMKov on 3/20/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prefix[n + 1];
    int ones = 0;
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ones += a;
        prefix[i + 1] = (a ? -1 : 1) + prefix[i];
//        cout << prefix[i + 1] << " ";
    }
//    cout << endl;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mx = max(mx, prefix[j + 1] - prefix[i]);
        }
    }
    cout << mx + ones << endl;
    return 0;
}