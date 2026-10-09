#include <iostream>
using namespace std;

int cnt[32];

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int run = 1 << 30;
        int pre = 0;

        for (int i = 30; i >= 0; i--, run >>= 1) {
            if ((r & run) && !(l & run)) break;
            else pre += (r & run);
        }
        int a = pre + run;
        int b = pre + run - 1;
        int c = (r == pre + run ? pre + run - 2 : pre + run + 1);
        cout << a << " " << b << " " << c << endl;
        // cout << (a ^ b) + (b ^ c) + (a ^ c) << endl;
    }
    return 0;
}

//6
// 30
// 6
// 44
// 18
// 78
// 30
// 2147483646