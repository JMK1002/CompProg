//
// Created by JMKov on 4/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int r[h];
    int c[w];
    int a = 0;
    for (int i = 0; i < h; i++) cin >> r[i];
    for (int i = 0; i < w; i++) cin >> c[i];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool filled = false;
            if (r[i] > j || c[j] > i) {
                filled = true;
                a++;
            }
            else if (r[i] == j || c[j] == i) {
                a++;
            }
            if (r[i] == j && filled) {
//                cout << i << " " << j << endl;
                cout << 0 << endl;
                return 0;
            }
            if (c[j] == i && filled) {
//                cout << i << " " << j << endl;
                cout << 0 << endl;
                return 0;
            }
        }
    }
    long long ans = 1;
    for (int i = 0; i < h * w - a; i++) {
        ans *= 2;
        ans %= 1000000007;
    }
//    cout << h * w - a << endl;
    cout << ans << endl;
    return 0;
}