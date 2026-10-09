#include <bits/stdc++.h>
using namespace std;

int n;
int h[200005];
int par[200005];
pair<int, int> rng[200005];

int getRoot(int a) {
	int res = a;
	while (par[res] != res) res = par[res];
	while (a != res) {
		int temp = par[a];
		par[a] = res;
		a = temp;
	}
	return res;
}


// combines b onto a
void combine(int a, int b) {
	int ra = getRoot(a);
	int rb = getRoot(b);
	if (ra == rb) return;
	par[rb] = ra;
	rng[ra] = {min(rng[ra].first, rng[rb].first), max(rng[ra].second, rng[rb].second)};
	h[ra] = max(h[rb], h[ra]);
}

void init() {
	for (int i = 0; i <= n + 1; i++) {
		par[i] = i;
		rng[i] = {i, i};
	}
	
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	h[0] = 2e9;
	h[n + 1] = 2e9;
	init();
	set<pair<int, int>> st; // {height, root}
	for (int i = 2; i <= n + 1; i++) {
		if (h[getRoot(i)] == h[getRoot(i - 1)]) combine(i, i - 1);
		else {
			st.insert({h[getRoot(i - 1)], getRoot(i - 1)});
		}
	}
	bool works = true;
	while (st.size() > 1) {
		int rt = st.begin()->second;
		int rl = getRoot(rng[rt].first - 1);
		int rr = getRoot(rng[rt].second + 1);
		if ((rng[rt].second - rng[rt].first + 1) % 2 == 1) works = false;
		if (h[rl] > h[rr]) swap(rl, rr);
		st.erase({h[rt], rt});
		st.erase({h[rl], rl});
		combine(rt, rl);
		st.insert({h[rt], rt});
		if (h[rr] == h[rt]) {
			combine(rt, rr);
			st.erase({h[rr], rr});
		}
	}
	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}