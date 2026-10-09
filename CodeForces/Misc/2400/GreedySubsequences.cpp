#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

int n, k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.assign(n, 0);
	fore(i, 0, n)
		cin >> a[i];
	return true;
}

int T = 0;
vector< vector<int> > g;
vector<int> tin, tout;

void dfs(int v) {
	tin[v] = T++;
	for(int to : g[v])
		dfs(to);
	tout[v] = T;
}

vector<int> Tmax, Tadd;

inline void push(int v) {
	Tadd[2 * v + 1] += Tadd[v];
	Tadd[2 * v + 2] += Tadd[v];
	Tadd[v] = 0;
}
inline int getmax(int v) {
	return Tmax[v] + Tadd[v];
}

void addVal(int v, int l, int r, int lf, int rg, int val) {
	if(l == lf && r == rg) {
		Tadd[v] += val;
		return;
	}
	int mid = (l + r) >> 1;
	push(v);
	if(lf < mid) addVal(2 * v + 1, l, mid, lf, min(mid, rg), val);
	if(rg > mid) addVal(2 * v + 2, mid, r, max(lf, mid), rg, val);
	Tmax[v] = max(getmax(2 * v + 1), getmax(2 * v + 2));
}

inline void solve() {
	g.resize(n + 1);
	tin.resize(n + 1, 0);
	tout.resize(n + 1, 0);
	vector<int> st;
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[st.back()] <= a[i])
			st.pop_back();
		int nxt = st.empty() ? n : st.back();
		g[nxt].push_back(i);
		st.push_back(i);
	}
	dfs(n);
	Tmax.assign(4 * (n + 1), 0);
	Tadd.assign(4 * (n + 1), 0);

	fore(i, 0, k - 1)
		addVal(0, 0, n + 1, tin[i], tout[i], +1);

	for(int l = 0; l + k <= n; l++) {
		addVal(0, 0, n + 1, tin[l + k - 1], tout[l + k - 1], +1);
		cout << getmax(0) << " ";
		addVal(0, 0, n + 1, tin[l], tout[l], -1);
	}
	cout << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);

	if(read()) {
		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}
