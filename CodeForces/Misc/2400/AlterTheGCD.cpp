#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int n;
int a[200005];
int b[200005];
int preA[200005];
int preB[200005];
int suffA[200005];
int suffB[200005];
map<pair<int, int>, int> latest;
map<pair<int, int>, int> earliest;
int t[1000000][2];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v][0] = a[tl];
        t[v][1] = b[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v][0] = __gcd(t[v*2][0], t[v*2+1][0]);
        t[v][1] = __gcd(t[v*2][1], t[v*2+1][1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {0, 0};
    if (l == tl && r == tr) {
        return {t[v][0], t[v][1]};
    }
    int tm = (tl + tr) / 2;
    pair<int, int> p1 = query(v*2, tl, tm, l, min(r, tm));
    pair<int, int> p2 = query(v*2+1, tm+1, tr, max(l, tm+1), r);
    return {__gcd(p1.first, p2.first), __gcd(p1.second, p2.second)};
}

pair<int, int> calc(int l, int r) {
    if (r <= l) return {0, 0};
    int aRet = 0;
    int bRet = 0;
    if (l != -1) {
        aRet = __gcd(aRet, preA[l]);
        bRet = __gcd(bRet, preB[l]);
    }
    if (r != n) {
        aRet = __gcd(aRet, suffA[r]);
        bRet = __gcd(bRet, suffB[r]);
    }
    pair<int, int> mid = query(1, 1, n, l + 1, r - 1);
    aRet = __gcd(aRet, mid.second);
    bRet = __gcd(bRet, mid.first);
    return {aRet, bRet};
}

// does the two pointers bull
int fuckThisProblem(pair<pair<int, int>, int> i, pair<pair<int, int>, int> j) {
    // yeah im too lazy to implement i pretty much solved this idc frik this
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    build(1, 1, n);

    preA[0] = a[0];
    preB[0] = b[0];
    for (int i = 1; i < n; i++) {
        preA[i] = __gcd(preA[i - 1], a[i]);
        preB[i] = __gcd(preB[i - 1], b[i]);
    }
    suffA[n] = 0;
    suffB[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffA[i] = __gcd(suffA[i + 1], a[i]);
        suffB[i] = __gcd(suffB[i + 1], b[i]);
    }

    for (int i = 0; i < n; i++) latest[{preA[i], preB[i]}] = i;
    for (int i = n - 1; i >= 0; i--) earliest[{suffA[i], suffB[i]}] = i;

    pair<int, int> mx = {-1, -1};
    int mxAmnt = -2064239746;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int amnt = __gcd(preA[i], suffB[i + 1]) + __gcd(preB[i], suffA[i + 1]);
        if (mxAmnt == amnt) cnt += 2;
        else if (mxAmnt < amnt) {
            mxAmnt = amnt;
            mx = {-1, i};
            cnt = 2;
        }
    }

    for (pair<pair<int, int>, int> i : latest) {
        for (pair<pair<int, int>, int> j : earliest) {
            pair<int, int> amnt = calc(i.second, j.second);
            if (mxAmnt <= amnt.first + amnt.second) {
                if (mxAmnt < amnt.first + amnt.second) cnt = 0;
                else cnt += fuckThisProblem(i, j);
                mxAmnt = amnt.first + amnt.second;
                mx = {i.second, j.second};
                
                ranges.insert({i.second, j.second});
            }
        }
    }
    cout << mxAmnt << endl;

    for (int i = 0; i <= n; i++) {
        a[i] = 0;
        b[i] = 0;
        preA[i] = 0;
        preB[i] = 0;
        suffA[i] = 0;
        suffB[i] = 0;
    }
    latest.clear();
    earliest.clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}