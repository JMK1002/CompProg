//
// Created by JMKov on 4/27/2024.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long n, k;

pair<long long, long long> trie[6000002][2];
long long code = 1;
long long p[6000002];
long long ind[200001];

long long nand(long long a, long long b, long long c) {
    long long g = 1;
    long long ret = 0;
    for (long long i = 0; i < c; i++) {
        ret += ((a & g) == (b & g)) * g;
        g *= 2;
    }
    return ret;
}

long long wnand(long long a, long long b, long long c) {
    long long g = 1;
    long long ret = 0;
    for (long long i = 0; i < c; i++) {
        ret += (!(a & g) && !(b & g)) * g;
        g *= 2;
    }
    return ret;
}

void update(long long v, long long index) {
    long long curr = 0;
    long long cnt = 1;
    for (long long i = k - 1; i >= 0; i--) {
        bool b = ((v >> i) & 1);
        if (!trie[curr][b].first) {
            trie[curr][b].first = code;
            trie[curr][b].second = cnt;
            p[code] = curr;
            code++;
        }
        curr = trie[curr][b].first;
        cnt++;
    }
    ind[index] = curr;
}


void solve() {
    cin >> n >> k;
    long long arr[n];
    map<long long, long long> exp;
    pair<pair<long long, long long>, long long> ret;
    ret = {{-1, -1}, -1};
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        if (exp.find(arr[i]) != exp.end()) {
            ret = {{i + 1, exp[arr[i]]}, wnand(arr[i], arr[i], k)};
        }
        else {
            exp[arr[i]] = i + 1;
        }
        update(arr[i], i);
    }
    if (!(ret.first.first == -1 && ret.first.second == -1 && ret.second == -1)) {
        cout << ret.first.first << " " << ret.first.second << " " << ret.second << endl;
        for (long long i = 0; i < code; i++) {
            trie[i][0] = {0,0};
            trie[i][1] = {0,0};
        }
        code = 1;
        return;
    }
    for (long long i = 0; i < n; i++) {
        while (ind[i] && (!trie[ind[i]][0].first || !trie[ind[i]][1].first)) {
            ind[i] = p[ind[i]];
        }
    }
//    for (long long i = 0; i < n; i++) cout << ind[i] << " ";
//    cout << endl;
    map<long long, long long> mp;
    vector<pair<long long, long long>> cand;
    for (long long i = 0; i < n; i++) {
        if (mp.find(ind[i]) == mp.end()) {
            mp[ind[i]] = i;
        }
        else {
            cand.push_back({mp[ind[i]], i});
        }
    }
    long long ans = -1;
    for (pair<long long, long long> p : cand) {
        long long x = nand(arr[p.first], arr[p.second], k);
//        cout << p.first << " " << p.second << " " << x << endl;
        if (ans < x) {
            ret = {p, wnand(arr[p.first], arr[p.second], k)};
            ans = x;
        }
    }
    if (ret.first.first == -1 && ret.first.second == -1 && ret.second == -1) cout << "1 2 0" << endl;
    else cout << ret.first.first + 1 << " " << ret.first.second + 1 << " " << ret.second << endl;
    for (long long i = 0; i < code; i++) {
        trie[i][0] = {0,0};
        trie[i][1] = {0,0};
    }
    code = 1;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
//    cout << ((3 ^ 12) & (1 ^ 12));
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}