//
// Created by JMKov on 7/4/2023.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int * arr;
int gcT[400010];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        gcT[v] = arr[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        gcT[v] = __gcd(gcT[v * 2], gcT[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0; // should still work since GCD(0, x) = |x|
    }
    else if (tl == l && tr == r) {
        return gcT[v];
    }
    else {
        int tm = (tl + tr) / 2;
        return __gcd(
            query(v * 2, tl, tm, l, min(tm, r)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
}


int main() {
    int n;
    cin >> n;
    arr = new int[n];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    build(1, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int gcd = query(1, 0, n - 1, l, r);
        int count = upper_bound(mp[gcd].begin(), mp[gcd].end(), r) - lower_bound(mp[gcd].begin(), mp[gcd].end(), l);
        cout << r - l + 1 - count << endl;
    }
//    for (int i = 0; i < 4 * n; i++) {
//        cout << gcT[i] << " ";
//    }
//    cout << endl;
//    cout << __gcd(0, 124) << endl;
//    cout << query(1, 0, n - 1, 2, 4) << endl;
    return 0;
}