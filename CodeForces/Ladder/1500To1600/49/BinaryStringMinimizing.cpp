//
// Created by JMKov on 5/20/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        long long k;
        string s;
        cin >> n >> k >> s;
        long long one = 0;
        for (int i = 0; i < n && k > 0; i++) {
            if (s[i] == '1') one++;
            else {
                s[i] = '1';
                s[i - min(one, k)] = '0';
                k -= min(one, k);
//                cout << s << endl;
            }
        }
        cout << s << endl;
    }
    return 0;
}