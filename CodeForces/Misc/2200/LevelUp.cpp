//
// Created by JMKov on 9/10/2024.
//
#include <iostream>
using namespace std;

long long n, q;
long long arr[200005];
long long cnt[200005];
long long t[1000000];

void build(long long l, long long r, long long v) {
    if (l > r) return;
    else if (l == r) {
        t[v] = cnt[l];
    }
    else {
        long long m = (l + r) / 2;
        build(l, m, v * 2);
        build(m + 1, r, v * 2 + 1);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

long long get(long long l, long long r, long long tl, long long tr, long long v) {
    if (l > r || tl > tr || tl > l || tr < r) return 0;
    else if (l == tl && r == tr) return t[v];
    else {
        long long m = (tl + tr) / 2;
        return get(l, min(r, m), tl, m, v * 2) +
            get(max(m + 1, l), r, m + 1, tr, v * 2 + 1);
    }
}

void inc(long long l, long long r, long long v, long long ind) {
    if (l > r || l > ind || r < ind) return;
    else if (l == r && l == ind) {
        t[v] += 1;
    }
    else {
        long long m = (l + r) / 2;
        inc(l, m, v * 2, ind);
        inc(m + 1, r, v * 2 + 1, ind);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> q;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
        long long low = 0;
        long long high = n + 2;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            long long amnt = get(1, mid, 1, n, 1);
            bool fights = (amnt / mid + 1) <= arr[i];

            if (fights) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        cnt[i] = high;
        inc(1, n, 1, high);
//        cout << high << " ";
    }
//    cout << endl;

    while (q--) {
        long long a, b;
        cin >> a >> b;
        if (cnt[a] <= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}