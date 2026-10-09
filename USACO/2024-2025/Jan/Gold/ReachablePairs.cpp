#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long n, m;
string s;

set<long long> adj[200005];
bool active[200005];
long long dsu[200005];
long long sz[200005]; // ! Only accurate for roots
long long cnt[200005]; // * counts amount of active nodes inside of a component
long long ans = 0;

long long getRoot(long long a) {
    if (a == dsu[a]) return a;
    long long ret = getRoot(dsu[a]);
    dsu[a] = ret;
    return ret;
}

void merge(long long a, long long b) {
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return;

    // ! we are merging a onto b, so sz[a] < sz[b]
    if (sz[a] > sz[b]) swap(a, b);
    dsu[a] = b;
    sz[b] += sz[a];
    ans += cnt[a] * cnt[b];
    // cout << cnt[a] << " " << cnt[b] << endl;
    cnt[b] += cnt[a];
}

void makeActive(long long v) {
    active[v] = true;
    long long rt = getRoot(v);
    ans += cnt[rt];
    // cout << cnt[rt] << endl;
    cnt[rt]++;
}

int main() {
    cin >> n >> m >> s;
    // s = "";
    // for (long long i = 0; i < n; i++) s += '0';
    for (long long i = 0; i < n; i++) {
        dsu[i] = i;
        sz[i] = 1;
        cnt[i] = 0;
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        // u = i; v = i + 1;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
        if (s[u] == s[v] && s[v] == '1') {
            merge(u, v);
        }
    }
    //// combine all 1 nodes together with edges between
    vector<long long> asdf;
    for (long long i = n - 1; i >= 0; i--) {
        makeActive(i);
        for (long long e : adj[i]) {
            if (s[e] == '1' || active[e]) {
                merge(i, e);
            }
        }
        asdf.push_back(ans);
    }
    reverse(asdf.begin(), asdf.end());
    for (long long i : asdf) cout << i << endl;
    // for (long long i = 0; i < 10; i++) cout << asdf[i] << endl;
    return 0;
}

// 7 8
// 0000000
// 6 2
// 1 2
// 2 3
// 6 3
// 1 3
// 1 7
// 4 5
// 2 7