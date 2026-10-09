//
// Created by JMKov on 5/27/2024.
//
#include <iostream>
#include <map>
using namespace std;

const long long mod = 998244353;

long long arr[302];
long long cnt[2][180004];
const long long md = 90002;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = rand() % 300;
    }
    cnt[0][arr[1] + md]++;
    long long ans = 1 + (arr[1] != 0);
    for (long long i = 2; i < n - 1; i++) {
        for (long long j = -90002; j < 90002; j++) {
            if (arr[i] + j < 90002) {
                cnt[1][arr[i] + j + md] += cnt[0][j + md];
                cnt[1][arr[i] + j + md] %= mod;
            }
            if (arr[i] - j >= -90002 && j != 0) {
                cnt[1][arr[i] - j + md] += cnt[0][j + md];
                cnt[1][arr[i] - j + md] %= mod;
            }
        }
        ans *= 2;
        ans -= cnt[1][md];
        if (ans < 0) ans += mod * 1000000000;
        ans %= mod;
        for (long long j = 0; j < 180004; j++) {
            cnt[0][j] = cnt[1][j];
            cnt[1][j] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}