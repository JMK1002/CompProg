#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int bt = 31;

int n;
pair<int, int> arr[200005];
int always[200005];
int t[1000000];
int pre[200005][bt];

void build(int v, int tl, int tr) {
    if (tl > tr) return;
    else if (tl == tr) {
        t[v] = always[tl - 1];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] | t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (tl > tr || l > r || tl > l || tr < r) return 0;
    else if (tl == l && tr == r) {
        return t[v];
    }
    else {
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) |
            query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    }
}

vector<int> getBin(int val) {
    vector<int> ret;
    int curr = 1;
    for (int i = 0; i < bt; i++) {
        if (curr & val) ret.push_back(1);
        else ret.push_back(0);
        curr <<= 1;
    }
    return ret;
}

int getInt(vector<int> vals) {
    int ret = 0;
    int run = 1;
    for (int i = 0; i < bt; i++) {
        ret += vals[i] * run;
        run <<= 1;
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        vector<int> a, b;
        a = getBin(arr[i].first);
        b = getBin(arr[i].second);
        int lastFixedBit = bt;

        vector<int> run;
        bool asdf = true;
        for (int j = bt - 1; j >= 0; j--) {
            if (asdf && a[j] != b[j]) {
                asdf = false;
            }
            if (asdf) {
                run.push_back(a[j]);
                lastFixedBit = j;
            }
            else run.push_back(0);
        }
        reverse(run.begin(), run.end());
        // for (int j : a) cout << j << " ";
        // cout << endl;
        always[i] = getInt(run);
        // cout << always[i] << " " << lastFixedBit << endl;
        for (int j = 0; j < bt; j++) {
            if (i == 0) pre[i][j] = (j < lastFixedBit) * b[j];
            else pre[i][j] = pre[i - 1][j] + (j < lastFixedBit) * b[j];
        }
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r--; l--;
        int fixed = query(1, 1, n, l + 1, r + 1);
        vector<int> asdf = getBin(fixed);
        bool allOnes = false;
        vector<int> imSoDone;
        for (int j = bt - 1; j >= 0; j--) {
            int amnt;
            if (j == 0) {
                cout << "";
            }
            if (l == 0) amnt = asdf[j] + pre[r][j];
            else amnt = asdf[j] + pre[r][j] - pre[l - 1][j];

            if (amnt >= 2) allOnes = true;
            if (allOnes) imSoDone.push_back(1);
            else imSoDone.push_back(amnt);
        }
        reverse(imSoDone.begin(), imSoDone.end());
        cout << getInt(imSoDone) << " ";
    }
    cout << endl;

    
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}