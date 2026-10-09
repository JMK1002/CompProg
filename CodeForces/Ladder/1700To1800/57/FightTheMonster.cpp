//
// Created by JMKov on 6/29/2023.
//
#include <iostream>
using namespace std;

bool sim(int hpy, int hpm, int dmy, int dmm) {
    return hpy / dmy + (hpy % dmy != 0) > hpm / dmm + (dmy % dmm != 0);
}

int main() {
    int hpy, aty, dey, hpm, atm, dem, h, a, d;
    cin >> hpy >> aty >> dey >> hpm >> atm >> dem >> h >> a >> d;
    int asdf = 0;
    int dmy = max(0, atm - dey);
    int dmm = max(0, aty - dem);
    if (aty <= dem) {
        asdf = (dem - aty + 1) * a;
        dmm = 1;
    }
    int ans = INT32_MAX;
    for (int at = 0; at < 1000; at++) {
        for (int de = 0; de < 1000; de++) {
            int v = asdf;
            v += at * a;
            v += de * d;
            v += h * max(0, ((dmy - de) * (hpm / (dmm + at) + (hpm % (dmm + at) != 0)) + 1) - hpy);
            ans = min(v, ans);
        }
    }
    cout << ans << endl;
    return 0;
}