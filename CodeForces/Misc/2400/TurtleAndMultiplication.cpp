#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 4000100;
const int N = 1000000;

int n, a[maxn], pr[maxn], tot, stk[maxn], top;
bool vis[maxn];

inline void init() {
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) {
			pr[++tot] = i;
		}
		for (int j = 1; j <= tot && i * pr[j] <= N; ++j) {
			vis[i * pr[j]] = 1;
			if (i % pr[j] == 0) {
				break;
			}
		}
	}
	mems(vis, 0);
}

inline bool check(int x) {
	if (x & 1) {
		return x + 1 + x * (x - 1) / 2 >= n;
	} else {
		return x * (x - 1) / 2 - x / 2 + 2 + x >= n;
	}
}

vector<pii> G[10000];

void dfs(int u) {
	while (G[u].size()) {
		pii p = G[u].back();
		G[u].pop_back();
		if (vis[p.scd]) {
			continue;
		}
		vis[p.scd] = 1;
		dfs(p.fst);
	}
	stk[++top] = pr[u];
}

void solve() {
	scanf("%d", &n);
	int l = 1, r = 10000, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	for (int i = 1; i <= ans; ++i) {
		vector<pii>().swap(G[i]);
	}
	int tot = 0;
	for (int i = 1; i <= ans; ++i) {
		for (int j = i; j <= ans; ++j) {
			if (ans % 2 == 0 && i % 2 == 0 && i + 1 == j) {
				continue;
			}
			G[i].pb(j, ++tot);
			G[j].pb(i, tot);
		}
	}
	for (int i = 1; i <= tot; ++i) {
		vis[i] = 0;
	}
	top = 0;
	dfs(1);
	reverse(stk + 1, stk + top + 1);
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", stk[i], " \n"[i == n]);
	}
}

int main() {
	init();
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}