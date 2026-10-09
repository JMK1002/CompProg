//
// Created by JMKov on 3/27/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prefix[n];
    cin >> prefix[0];
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        prefix[i] = (a) * ((i & 1) == 0 ? 1 : -1) + prefix[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = (prefix[n - 1] - prefix[i]) * -1;
        if (i != 0) {
            a = prefix[i - 1];
        }
        ans += (a + b) == 0;
    }
    cout << ans << endl;
    return 0;
}