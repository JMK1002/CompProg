#include <iostream>
#include <set>
#include <map>
using namespace std;

int n;
int arr[200005][2];
int t[3000000];
map<int, int> conv;

void update(int v, int tl, int tr, int ind, int val) {
	if (tl > tr || tl > ind || tr < ind) return;
	else if (tl == tr) {
		t[v] = val;
	}
	else {
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, ind, val);
		update(v * 2 + 1, tm + 1, tr, ind, val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (tl > tr || l > r || tl > l || tr < r) return 0;
	else if (tl == l && tr == r) {
		return t[v];
	}
	else {
		int tm = (tl + tr) / 2;
		return query(v * 2, tl, tm, l, min(tm, r)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
}

void solve() {
	cin >> n;
	int ans = 0;
	set<int> vals;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		vals.insert(arr[i][0]);
		vals.insert(arr[i][1]);
	}
	int cnt = 0;
	for (int i : vals) {
		conv[i] = ++cnt;
	}
	for (int i = 0; i < n; i++) {
		arr[i][0] = conv[arr[i][0]];
		arr[i][1] = conv[arr[i][1]];
	}
	for (int i = 0; i < n; i++) {
		int l = arr[i][0];
		int r = arr[i][1];
		update(1, 1, 2 * n + 1, l, query(1, 1, 2 * n + 1, l, l) + 1);
		update(1, 1, 2 * n + 1, r + 1, query(1, 1, 2 * n + 1, r + 1, r + 1) - 1);
		ans = max(ans, query(1, 1, 2 * n + 1, 1, r));
		cout << ans << " ";
	}
	cout << endl;
	for (int i = 1; i <= 2 * n + 1; i++) update(1, 1, 2 * n + 1, i, 0);
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