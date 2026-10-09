//
// Created by JMKov on 6/27/2024.
//
#include <iostream>
using namespace std;

int n;
int a[200004];
int b[200004];

void solve() {
    cin >> n;
    int ar = 0;
    int br = 0;
    int same[3] = {0,0,0};
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] > b[i]) ar += a[i];
        else if (b[i] > a[i]) br += b[i];
        else same[a[i] + 1]++;
    }
//    cin >> ar >> br >> same[0] >> same[2];
    if (ar < br) {
        if (ar + same[2] <= br) {
            ar += same[2];
            same[2] = 0;
        }
        else {
            int x = br - ar;
            ar += x;
            same[2] -= x;
        }
    }
    else {
        if (br + same[2] <= ar) {
            br += same[2];
            same[2] = 0;
        }
        else {
            int x = ar - br;
            br += x;
            same[2] -= x;
        }
    }
    ar += same[2] / 2 + (same[2] % 2 == 1);
    br += same[2] / 2;
    cout << min((ar + br - same[0] + 100000000) / 2 - 50000000, min(ar, br)) << endl;
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
        b[i] = 0;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}