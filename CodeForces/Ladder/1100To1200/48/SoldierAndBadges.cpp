//
// Created by JMKov on 3/23/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int numCount[2 * n + 1] = { 0 };
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        numCount[a]++;
    }
    int ans = 0;
    for (int i = 0; i < 2 * n + 1; i++) {
        if (numCount[i] > 1) {
            numCount[i + 1] += numCount[i] - 1;
            ans += numCount[i] - 1;
            numCount[i] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}