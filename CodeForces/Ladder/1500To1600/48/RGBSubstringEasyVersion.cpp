//
// Created by JMKov on 5/20/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        char chars[] = {'R', 'G', 'B'};
        int mnChange = 1000000000;
        for (int i = 0; i < 3; i++) {
            int change = 0;
            bool list[n];
            for (int j = 0; j < n; j++) {
                list[j] = chars[(i + j) % 3] != s[j];
                change += list[j];
                if (j == k - 1) mnChange = min(mnChange, change);
                if (j >= k) {
                    change -= list[j - k];
                    mnChange = min(mnChange, change);
                }
            }
            mnChange = min(mnChange, change);
        }
        cout << mnChange << endl;
    }
    return 0;
}