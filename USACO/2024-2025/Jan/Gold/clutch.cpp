#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

const pair<long long, long long> def = {0, LLONG_MAX};

long long n, T, X, Y;
pair<long long, long long> t[8000005]; // * before, after
pair<long long, long long> lazy[8000005];
long long sq[8000005];
long long asdf[400000];

void pushDown(long long v) {
    t[v] = {max(t[v].first, lazy[v].first), min(t[v].second, lazy[v].second)};

    lazy[v * 2] = {max(lazy[v].first, lazy[v * 2].first), min(lazy[v].second, lazy[v * 2].second)};
    lazy[v * 2 + 1] = {max(lazy[v].first, lazy[v * 2 + 1].first), min(lazy[v].second, lazy[v * 2 + 1].second)};
    lazy[v] = def;
}

void update(long long v, long long tl, long long tr, long long l, long long r, pair<long long, long long> val) {
    if (l > r || tl > tr) return;
    else if (l == tl && r == tr) {
        lazy[v] = {max(lazy[v].first, val.first), min(lazy[v].second, val.second)};
        pushDown(v);
    }
    else {
        pushDown(v);

        long long tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), val);
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
        t[v] = {max(t[v * 2].first, t[v * 2 + 1].first), min(t[v * 2].second, t[v * 2 + 1].second)};
    }
}

pair<long long, long long> get(long long v, long long tl, long long tr, long long ind) {
    if (tl > ind || tr < ind) return def;
    else if (tl == tr) {
        pushDown(v);
        return t[v];
    }
    else {
        pushDown(v);

        long long tm = (tl + tr) / 2;
        pair<long long, long long> p1 = get(v * 2, tl, tm, ind);
        pair<long long, long long> p2 = get(v * 2 + 1, tm + 1, tr, ind);
        return {max(p1.first, p2.first), min(p1.second, p2.second)};
    }
}

int main() {
    cin >> n >> T >> X >> Y;
    for (long long i = 0; i < 8000005; i++) {
        t[i] = def;
        lazy[i] = def;
        sq[i] = i * i;
    }

    long long lVal = X;
    long long rVal = X;
    for (long long i = 0; i < n; i++) {
        long long s, x, y;
        cin >> s >> x >> y;
        update(1, 1, 1000000, 1, x - 1, {0, y});
        update(1, 1, 1000000, x + 1, LLONG_MAX, {y, def.second});
        pair<long long, long long> p = get(1, 1, 1000000, lVal);
        while (p.first > p.second) {
            lVal--;
            p = get(1, 1, 1000000, lVal);
        }

        long long ans = X - lVal + Y - min(Y, p.second) + (upper_bound(sq, sq + 8000005, sq[lVal] + sq[min(Y, p.second)]) - sq - 1);
        // cout << lVal << " " << min(Y, p.second) << endl;

        p = get(1, 1, 1000000, rVal);
        while (p.first > p.second) {
            rVal++;
            p = get(1, 1, 1000000, rVal);
        }
        ans = min(ans, rVal - X + max(Y, p.first) - Y + (upper_bound(sq, sq + 8000005, sq[rVal] + sq[max(Y, p.first)]) - sq - 1));
        // cout << rVal << " " << max(Y, p.first) << endl;
        asdf[s] = ans;
    }
    asdf[0] = upper_bound(sq, sq + 8000000, sq[X] + sq[Y]) - sq - 1;
    for (int i = 0; i < T; i++) {
        if (asdf[i] == 0) asdf[i] = asdf[i - 1];
        cout << asdf[i] << endl;
    }
}