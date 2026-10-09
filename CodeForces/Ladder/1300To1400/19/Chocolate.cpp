//
// Created by JMKov on 4/7/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int aaaaaaaa = -200;
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        bool nut;
        cin >> nut;
        if (nut) {
            ans *= max(aaaaaaaa, 1);
            aaaaaaaa = 1;
        }
        else {
            aaaaaaaa++;
        }
//        cout << aaaaaaaa << endl;
//        cout << ans << endl;
    }
    if (aaaaaaaa < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}