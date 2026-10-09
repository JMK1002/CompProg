//
// Created by JMKov on 6/27/2024.
//
#include <iostream>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < b.size(); i++) {
        int ind = i;
        int cnt = 0;
        for (int j = 0; j < a.size() && ind < b.size(); j++) {
            if (b[ind] == a[j]) {
                ind++;
                cnt++;
            }
        }
        res = max(res, cnt);
//        cout << cnt << endl;
    }
    cout << a.size() + b.size() - res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}