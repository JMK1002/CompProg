#include <bits/stdc++.h>
using namespace std;

const int bt = 30;

vector<int> get(int l, int r) {
	if (l == r) return {l};
	int cnt = 30;
	int run = (1 << bt);
	int extra = 0;
	while (run) {
		if ((l & run) != (r & run)) break;
		extra += (l & run);
		run >>= 1;
		cnt--;
	}
	l -= extra;
	r -= extra;
	vector<int> ans(r - l + 1);
	for (int i = 0; i < r - l + 1; i++) ans[i] = l + i;
	int ptr = run;
	cnt = 0;
	while (ptr <= r && (run - 1) - (ptr - run) >= l) {
		swap(ans[ptr - l], ans[(run - 1) - (ptr - run) - l]);
		ptr++;
		cnt++;
	}
	if (ans[0] == l) {
		vector<int> v = get(l, run - cnt - 1);
		for (int i = 0; i < v.size(); i++) ans[i] = v[i];
	}
	else if (ans.back() == r) {
		vector<int> v = get(run + cnt, r);
		for (int i = v.size() - 1; i >= 0; i--) {
			ans[ans.size() - 1 - (v.size() - 1 - i)] = v[i];
		}
	}
	for (int i = 0; i < ans.size(); i++) ans[i] += extra;
	return ans;

	// vector<int> vl = get(l, run - 1);
	// vector<int> vr = get(0, r - run);
	// if (vr.size() >= vl.size()) {
	// 	for (int i = 0; i < vl.size(); i++) vl[i] += run;
	// 	for (int i = 0; i < vr.size() - vl.size(); i++) vr[i] += run;
	// }
	// else {
	// 	for (int i = 0; i < vr.size(); i++) vl[vl.size() - 1 - i] += run;
	// }
	// vector<int> ans = vl;
	// for (int i = 0; i < vr.size(); i++) ans.push_back(vr[i]);
	// for (int i = 0; i < ans.size(); i++) ans[i] += extra;


	// int run = 1;
	// while (run * 2 <= r) run <<= 1;
	// vector<int> ans(r + 1);
	// for (int i = 0; i < run; i++) ans[i] = run - i - 1;
	// for (int i = 0; i <= (r - run); i++) ans[run - i - 1] += run;
	// vector<int> v = get(l, r - run);
	// for (int i = run; i <= r; i++) ans[i] = v[i - run];
	// return ans;
}

void solve() {
	int l, r;
	cin >> l >> r;
	vector<int> v = get(l, r);
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) ans += ((l + i) | v[i]);
	cout << ans << endl;
	for (int i : v) cout << i << " ";
	cout << endl;
}

int main() {
	// cout << (1 << 31) << endl;
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}