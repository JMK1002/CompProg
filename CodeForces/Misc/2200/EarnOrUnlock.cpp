#include <iostream>
#include <bitset>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    bitset<200005> dp;
    dp[0] = true;
    long long ans = 0;
    long long sum = 0;
    for (long long i = 0; i < 200000; i++) {
        long long v;
        if (i < n) cin >> v;
        else v = 0;
        sum += v;
        if (dp[i]) {
            ans = max(ans, sum - i);
        }
        dp |= (dp << v);
        dp[i] = false;
    }
    cout << ans << endl;
    return 0;
}