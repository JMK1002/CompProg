//
// Created by JMKov on 5/18/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int input[n][3];
        int l = m;
        int r = m;
        int t = 0;
        bool done = false;
        for (int i = 0; i < n; i++) {
            cin >> input[i][0] >> input[i][1] >> input[i][2];
        }
        for (int i = 0; i < n; i++) {
            l -= input[i][0] - t;
            r += input[i][0] - t;
            t = input[i][0];
            if (l <= input[i][1] && r >= input[i][1]) {
                l = input[i][1];
                r = min(input[i][2], r);
            }
            else if (l <= input[i][2] && r >= input[i][2]) {
                l = max(input[i][1], l);
                r = input[i][2];
            }
            else if (l < input[i][1] || r > input[i][2]) {
                cout << "NO" << endl;
                done = true;
                break;
            }
//            cout << l << " " << r << endl;
        }
        if (done) continue;
        cout << "YES" << endl;
    }
}