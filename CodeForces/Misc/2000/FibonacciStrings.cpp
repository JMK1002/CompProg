//
// Created by JMKov on 6/5/2024.
//
#include <iostream>
#include <set>

using namespace std;

long long n;
long long arr[102];
multiset<long long> run;
long long fib[100];
long long prefib[80];

void solve() {
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        run.insert(arr[i]);
        sum += arr[i];
    }



    long long cnt = 0;
    bool ans = true;

    long long ind = lower_bound(prefib, prefib + 79, sum) - prefib;
    if (sum == prefib[ind]) cnt = ind;
    else ans = false;

    long long k = -1;

    while (!run.empty() && cnt) {
        auto p = (--run.end());
        if (*p < fib[cnt]) {
            ans = false;
            break;
        }
        long long x = *p;
        run.erase(run.find(x));
        if (k > 0) run.insert(k);
        k = x - fib[cnt];
        cnt--;
    }
    if (run.empty() && k != 0) {
        ans = false;
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    run.clear();
}

int main() {
    long long t;
    cin >> t;
    fib[1] = 1;
    for (long long i = 2; i < 100; i++) fib[i] = fib[i - 1] + fib[i - 2];
    for (long long i = 1; i < 80; i++) prefib[i] = prefib[i - 1] + fib[i];
    while (t--) {
        solve();
    }
    return 0;
}