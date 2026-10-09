#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

const long long MAXN = 4000100;

// t is tree, T is time
long long n, T, X, Y;
pair<long long, long long> t[MAXN]; // ! {bf, af}
pair<long long, long long> lazy[MAXN];
long long squares[MAXN];
long long ans[1000000];

void push(long long v) {
    if (lazy[v].first == 0 && lazy[v].second == Y) return;

    t[v * 2].first = max(t[v * 2].first, lazy[v].first);
    t[v * 2].second = min(t[v * 2].second, lazy[v].second);

    t[v * 2 + 1].first = max(t[v * 2 + 1].first, lazy[v].first);
    t[v * 2 + 1].second = min(t[v * 2 + 1].second, lazy[v].second);
    lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
    lazy[v] = {0, Y};
}

void update(long long v, long long tl, long long tr, long long l, long long r, pair<long long, long long> new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = {max(new_val.first, t[v].first), min(new_val.second, t[v].second)};
        lazy[v] = new_val;
    } else {
        push(v);
        long long tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        t[v] = {max(t[v * 2].first, t[v * 2 + 1].first), min(t[v * 2].second, t[v * 2 + 1].second)};
    }
}

pair<long long, long long> query(long long v, long long tl, long long tr, long long l, long long r) {
    if (l > r)
        return {0, Y};
    if (l == tl && tr == r)
        return t[v];
    push(v);
    long long tm = (tl + tr) / 2;
    pair<long long, long long> p1 = query(v*2, tl, tm, l, min(r, tm));
    pair<long long, long long> p2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> T >> X >> Y;
    for (long long i = 0; i < MAXN; i++) {
        t[i] = {0, Y};
        lazy[i] = {0, Y};
        squares[i] = (long long) i * i;
    }
    long long xVal = X;
    long long xVal2 = X;
    long long upper = 1000005;
    for (long long i = 0; i < n; i++) {
        long long s, x, y;
        cin >> s >> x >> y;
        update(1, 1, upper, 1, x - 1, {0, y});
        update(1, 1, upper, x + 1, upper, {y, Y});
        pair<long long, long long> p = query(1, 1, upper, xVal, xVal);
        while (p.first > p.second) {
            xVal--;
            p = query(1, 1, upper, xVal, xVal);
        }
        // cout << xVal << " " << p.second << endl;
        long long asdf = upper_bound(squares, squares + 8000000, squares[xVal] + squares[p.second]) - squares;
        // cout << (asdf + X - xVal + Y - p.second - 1) << endl;
        ans[s] = (asdf + X - xVal + Y - p.second - 1);

        p = query(1, 1, upper, xVal2, xVal2);
        while (min(p.first, Y) > p.second) {
            xVal2++;
            p = query(1, 1, upper, xVal2, xVal2);
        }
        asdf = upper_bound(squares, squares + 8000000, squares[xVal2] + squares[max(Y, p.first)]) - squares;
        ans[s] = min(ans[s], (asdf + xVal2 - X + abs(Y - max(Y, p.first)) - 1));
    }
    ans[0] = upper_bound(squares, squares + 8000000, squares[X] + squares[Y]) - squares - 1;
    for (int i = 0; i < T; i++) {
        if (ans[i] == 0) ans[i] = ans[i - 1];
        cout << ans[i] << endl;
    }
    return 0;
}