//
// Created by JMKov on 6/8/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        string s;
        cin >> x >> s;
//        s = "";
//        for (int i = 0; i < 500; i++) {
//            s += "3";
//        }
//        x = 100000;
        long long ans = s.size();
        int l = 0;
        vector<int> vals;
        for (char i : s) vals.push_back(i - '0');
        while (l < x && !vals.empty()) {
            l++;
            int v = vals[l - 1];
            ans += (ans - l) * (v - 1);
//            cout << ans << endl;
            if (ans < 0) {
                ans += 1000000007;
            }
            ans %= 1000000007;

//            for (int i : vals) cout << i << " ";
//            cout << endl;
            if (vals.size() >= x || v == 1) {
                continue;
            }
            int asdf = vals.size();
            for (int i = 1; i < v; i++) {
                for (int j = l; j < asdf; j++) {
                    vals.push_back(vals[j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}