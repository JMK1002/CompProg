#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tree_set = tree<int, null_type, less<int>, rb_tree_tag,
                      tree_order_statistics_node_update>;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y,
    Z;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
const int MOD = 998244353;
int parent[202020];
int sz[202020];
int csz[202020];
int find(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = find(parent[x]);
}
bool uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return false;
  }
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  parent[y] = x;
  sz[x] += sz[y];
  csz[x] += csz[y];
  return true;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> N;
    iota(parent, parent + N + 1, 0);
    fill(sz, sz + N + 1, 1);
    fill(csz, csz + N + 1, 1);
    vector<int> pv(N + 1);
    vector<int> cv(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> pv[i];
    }
    for (int i = 1; i <= N; i++) {
      cin >> cv[i];
    }
    vector<int> idxv(N);
    iota(idxv.begin(), idxv.end(), 1);
    sort(idxv.begin(), idxv.end(), [&](int a, int b) { return pv[a] < pv[b]; });
    ll ans = 1;
    // we go through the permutation in ascending order
    // each 'union' will represent a co-swappable group
    // we 'fix' the positions of elements in the group in ascending order
    // as positions are 'fixed', adjacent groups could be checked for
    // swappability and merged into one group, since it will be confirmed that
    // no larger element exists between the two groups

    // 1. merge adjacent groups first
    set<pi> idxst; // this will be used for checking adjacent groups later on
    for (int i = 1; i <= N; i++) {
      if (cv[i] == cv[i - 1]) {
        uni(i, i - 1);
      }
      idxst.insert({i, cv[i]});
    }
    // 2. go through the permutation in ascending order
    for (auto ci : idxv) {
      auto iter = idxst.find({ci, cv[ci]});
      ans *= csz[find(ci)];
      ans %= MOD;
      csz[find(
          ci)]--; // 'fixing' the position of ci removes 1 'degree of freedom'

      if (iter != idxst.begin() && iter != prev(idxst.end())) {
        auto previter = prev(iter);
        auto nextiter = next(iter);
        if (previter->second == nextiter->second) {
          uni(previter->first, nextiter->first);
        }
      }
      idxst.erase(iter);
    }
    cout << ans << '\n';
  }
}