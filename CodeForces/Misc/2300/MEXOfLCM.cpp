#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

long long n;
long long arr[300006];
set<long long> cnt;

long long calc(long long a, long long b) {
    if (a == 0 && b == 0) return 0;
    if (b == 0) swap(a, b);
    if (a == 0) {
        if (b > n * n) return -1;
        else return b;
    }
 
    long long g = __gcd(a, b);
    if (
        a == -1 ||
        b == -1 ||
        a / g  > (n * n + 1) / b
    ) {
        return -1;
    }
    else {
        return lcm(a, b);
    }
}

void solve() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        if (arr[i - 1] != x) arr[i] = x;
        else {
            n--;
            i--;
        }
    }


    set<long long> run;
    for (long long i = 1; i <= n; i++) {
        set<long long> temp;
        for (long long j : run) temp.insert(calc(j, arr[i]));
        for (long long j : run) cnt.insert(j);
        run = temp;
        run.insert(arr[i]);
    }
    for (long long j : run) cnt.insert(j);

    long long asdf = 1;
    while (cnt.find(asdf) != cnt.end()) asdf++;
    cout << asdf << endl;

    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    cnt.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 1
// 4
// 1000000000 10000000000 1 1000