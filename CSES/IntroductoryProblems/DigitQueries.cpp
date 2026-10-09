//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        long long cnt = 1;
        long long pw = 1;
        while (n > cnt * 9 * pw) {
            n -= cnt * 9 * pw;
            cnt++;
            pw *= 10;
        }
        if (n % cnt == 0) {
            cout << to_string(n / cnt + pw - 1)[(n - 1) % cnt] << endl;
        }
        else cout << to_string(max(pw, n / cnt + pw))[(n - 1) % cnt] << endl;
    }
    return 0;
}