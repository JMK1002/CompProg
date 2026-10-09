#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long n;
int m;
struct Node {
	int pm, ans;
	vector<int> d;
};
map<long long, Node> d;
Node cal(long long n) {
	if (d.count(n)) return d[n];
	d[n] = Node();
	if (n == 0) {
		d[n].pm = 1;
		d[n].ans = 0;
		d[n].d.resize(m + 1, 0);
		return d[n];
	}
	if (n == 1) {
		d[n].pm = m;
		d[n].ans = 1LL * m * (m + 1) / 2 % M;
		d[n].d.resize(m + 1, 0);
		for (int i = 1; i <= m; ++i) {
			d[n].d[i] = i;
		}
		return d[n];
	}
	d[n].d.resize(m + 1, 0);
	Node &cur = d[n];
	long long szl = 0, szr = 0;
	int last = 63 - __builtin_clzll(n);
	// cerr << n << " : " << last << '\n';
	if ((n >> (last - 1) & 1)) {
		// cerr << "DB>> " << n << " : " << last << " : " << (1LL << last) - 1 << '\n';
		szl = (1LL << (long long)last) - 1;
		szr = n - szl - 1;
	}
	else {
		szr = (1LL << (long long)(last - 1)) - 1;
		szl = n - szr - 1;
	}
	// cerr << n << " : " << cur.ans << '\n';
	Node l = cal(szl), r = cal(szr);
	cur.pm = 1LL * m * l.pm % M * r.pm % M;
	cur.ans = 0;
	int pv = 0;
	for (int i = 1; i <= m; ++i) {
		cur.d[i] = (cur.d[i] + 1LL * l.d[i] * i % M * r.pm) % M;
		cur.d[i] = (cur.d[i] + 1LL * r.d[i] * i % M * l.pm) % M;
		cur.d[i] = (cur.d[i] + 1LL * i * l.pm % M * r.pm) % M;
		int cv = 0;
		cv = (cv + 1LL * l.ans * m % M * r.pm) % M;
		cv = (cv + 1LL * r.ans * m % M * l.pm) % M;
		cv = (cv + cur.d[i]) % M;
		cv = (cv + 1LL * l.d[i] * i % M * r.d[i]) % M;
		cur.ans = (cur.ans + 1LL * (cv - pv + M) * i) % M;
		pv = cv;
	}
	return d[n];
}
void solve() {
	cin >> n >> m;
	d.clear();
	cout << cal(n).ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
	    // freopen("TEST.inp", "r", stdin);
	    // freopen("TEST.out", "w", stdout);
    #else
    	// freopen("TEST.inp", "r", stdin);
    	// freopen("TEST.out", "w", stdout);
    #endif
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}   
    return 0;
}