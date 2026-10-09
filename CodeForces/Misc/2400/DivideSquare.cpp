//
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> pint;
typedef tuple<int, int, int> tint;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

struct BITree {
	int t[N];
	int Lowbit(int x) {
		return x & -x;
	}
	void Modify(int x, int det) {
		x++;
		for (; x < N; x += Lowbit(x))
			t[x] += det;
	}
	int Query(int x) {
		x++;
		int ret = 0;
		for (; x; x -= Lowbit(x))
			ret += t[x];
		return ret;
	}
};
BITree bt;

vector<pint> det[N];

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<tint> hor;

	for (int i = 1; i <= n; i++) {
		int y, l, r;
		cin >> y >> l >> r;
		hor.push_back(make_tuple(y, l, r));
	}
	sort(all(hor));
	ll ans = 1;
	for (int i = 1; i <= m; i++) {
		int x, l, r;
		cin >> x >> l >> r;
		det[l].push_back(make_pair(x, 1));
		det[r + 1].push_back(make_pair(x, -1));
		if (l == 0 && r == int(1e6)) ans++;
	}
	bt.Modify(0, 1);
	bt.Modify(1e6, 1);

	auto p = hor.begin();
	for (int i = 0; i <= int(1e6); i++) {
		for (auto x: det[i])
			bt.Modify(x.fi, x.se);
		while (p != hor.end() && get<0>(*p) == i) {
			int cnt = bt.Query(get<2>(*p)) - bt.Query(get<1>(*p) - 1);
			ans += cnt - 1;
			p++;
		}
	}
	cout << ans << endl;

	return 0;
}
