//
// Created by JMKov on 5/27/2024.
//
#include <iostream>
#include <set>

using namespace std;

long long n, k, x;
long long arr[200005];
long long pre[200005];
multiset<long long> run;

long long mxSum(int mn, int mx) {
    long long ret = INT64_MIN;
    for (int i = 0; i <= n; i++) {
        if (i >= mn) run.insert(pre[i - mn]);
        if (i > mx) run.erase(run.find(pre[i - mx - 1]));
        ret = max(ret, (run.empty()) ? INT64_MIN : pre[i] - *(run.begin()));
    }
    run.clear();
    return ret;
}

void solve() {
    cin >> n >> k >> x;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = 1;
        arr[i] -= x;
    }
    for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i - 1];

    long long ans = 0;
    if (x < 0) {
        x *= 2;
        ans = max(ans, mxSum(1, n - k));
        for (long long i = n - k; i <= n; i++) {
            long long ret = 0;
            for (long long j = 0; j < n - i + 1; j++) {
                ret = max(ret, pre[j + i] - pre[j] + x * (i - (n - k)));
            }
            ans = max(ans, ret);
        }
    }
    else {
        x *= 2;
        ans = max(ans, mxSum(k, n) + k * x);
        for (int i = 1; i < k; i++) {
            ans = max(ans, mxSum(i, i) + i * x);
        }
    }

    cout << ans << endl;
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        pre[i] = 0;
    }
    run.clear();
}

int main() {
    cin.tie();
    istream::sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        solve();
//        cin >> n;
//        for (int i = 0; i < n; i++) cin >> arr[i];
//        for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i - 1];
//        cout << mxSum(1, 1) << " " << mxSum(2,2) << endl;
//        cout << mxSum(2, 3) << " " << mxSum(1, 3) << endl;
    }
    return 0;
}
//100
//1 1 3
//1
//1 1 2
//2
//1 1 -2
//-4
//3 1 -100
//1 10 -20