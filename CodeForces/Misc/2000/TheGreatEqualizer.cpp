//
// Created by JMKov on 5/23/2024.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long n, q;
long long a[200004];
multiset<long long> arr;
multiset<long long> diffs;
map<long long, long long> cnt;

void clear() {
    for (long long i = 0; i < n; i++) a[i] = 0;
    arr.clear();
    diffs.clear();
    cnt.clear();
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        arr.insert(a[i]);
    }
    if (n == 1) {
        cin >> q;
        for (int i = 0; i < q; i++) {
            int u;
            cin >> u >> u;
            cout << u << " ";
        }
        cout << endl;
        clear();
        return;
    }
    long long last = -1;
    for (long long i : arr) {
        if (last == -1) {
            last = i;
            continue;
        }
        diffs.insert(i - last);
        cnt[i - last]++;
        last = i;
    }
    long long asdf = 3000;
    long long ans = asdf * arr.size();
    ans -= asdf - *(--diffs.end());
    for (pair<long long, long long> p : cnt) {
        ans -= p.second * (asdf - p.first);
    }

    cin >> q;
    long long lastMax = *(--diffs.end());
    for (long long i = 0; i < q; i++) {
        long long ind, x;
        cin >> ind >> x;
        ind--;
        auto p = arr.find(a[ind]);
        if (p != arr.begin()) {
            p--;
            diffs.erase(diffs.find(a[ind] - *p));
            cnt[a[ind] - *p]--;
            ans += (asdf - (a[ind] - *p));
            p++;
        }
        if (p != (--arr.end())) {
            p++;
            diffs.erase(diffs.find(*p - a[ind]));
            cnt[*p - a[ind]]--;
            ans += (asdf - (*p - a[ind]));
            p--;
        }
        if (p != (--arr.end()) && p != arr.begin()) {
            p--;
            long long x = *p;
            p++;
            p++;
            long long y = *p;
            p--;
            diffs.insert(y - x);
            cnt[y - x]++;
            ans -= (asdf - (y - x));
        }
        arr.erase(arr.find(a[ind]));
        p = arr.lower_bound(x);
        if (p != arr.begin() && p != arr.end()) {
            p--;
            long long x = *p;
            p++;
            long long y = *p;
            diffs.erase(diffs.find(y - x));
            cnt[y - x]--;
            ans += (asdf - (y - x));
        }
        if (p != arr.begin()) {
            p--;
            diffs.insert(x - *p);
            cnt[x - *p]++;
            ans -= (asdf - (x - *p));
            p++;
        }
        if (p != arr.end()) {
            diffs.insert(*p - x);
            cnt[*p - x]++;
            ans -= (asdf - (*p - x));
        }
        arr.insert(x);
        a[ind] = x;
        ans += *(--diffs.end()) - lastMax;
        lastMax = *(--diffs.end());
        cout << ans + (*arr.begin()) << " ";
    }
    cout << endl;
    clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}