//
// Created by JMKov on 5/14/2024.
//
#include <iostream>
using namespace std;

long long mod(long long a) {
    if (a < 0) a += 1000040017 * 9223000000;
    return a % 1000040017;
}

long long binpow(long long a, long long b) {
    long long ans = 1;
    long long run = a;
    while (b) {
        if (b & 1) {
            ans *= run;
            ans = mod(ans);
        }
        run *= run;
        run = mod(run);
        b >>= 1;
    }
    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, q;
        string s;
        cin >> n >> q >> s;
        bool arr[n];
        long long pre[n];
        arr[0] = true; arr[1] = true;
        pre[0] = 1; pre[1] = 2;
        for (long long i = 2; i < n; i++) {
            arr[i] = s[i - 2] == s[i];
            pre[i] = pre[i - 1] + arr[i];
        }
        long long preh[n + 1];
        long long suffh[n + 1];
        preh[0] = 0;
        suffh[n] = 0;
        for (long long i = 0; i < n; i++) {
            preh[i + 1] = mod(preh[i] * 26) + s[i] - 'a';
            preh[i + 1] = mod(preh[i + 1]);
        }
        for (long long i = n - 1; i >= 0; i--) {
            suffh[i] = mod(suffh[i + 1] * 26) + s[i] - 'a';
            suffh[i] = mod(suffh[i]);
        }
//        for (int i = 0; i <= n; i++) cout << preh[i] << " ";
//        cout << endl;
//        for (int i = 0; i <= n; i++) cout << suffh[i] << " ";
//        cout << endl;

        while (q--) {
            long long l, r;
            cin >> l >> r;
            l--; r--;
            long long len = r - l + 1;
            long long a = pre[r] - ((l == 0) ? 0 : pre[l - 1]);
            a += !arr[l] + !arr[l + 1];
//            cout << binpow(10, 10) << endl;
//            cout << a << " " << len << " ";
//            cout << mod(preh[r + 1] - mod(preh[l] * binpow(26, len))) << " " << mod(suffh[l] - mod(suffh[r + 1] * binpow(26, len))) << " ";
            long long ans = 0;
            if (a != len) ans = (len - 1) * (len) / 2 - 1;
            if (a == len && s[l] != s[l + 1]) ans = ((len) / 2) * ((len) / 2 + 1);
            else if (mod(suffh[l] - mod(suffh[r + 1] * binpow(26, len))) != mod(preh[r + 1] - mod(preh[l] * binpow(26, len)))) ans += len;
            cout << ans << endl;
        }
    }
    return 0;
}