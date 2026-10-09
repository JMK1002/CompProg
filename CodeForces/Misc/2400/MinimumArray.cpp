#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long n;
long long arr[500005];
long long pre[500005];
vector<pair<pair<long long, long long>, long long>> ops;
set<long long> curr;

void cl() {
	for (long long i : curr) pre[i] = 0;
	curr.clear();
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	long long q;
	cin >> q;
	long long ans = -1;
	for (long long i = 0; i < q; i++) {
		long long l, r, v;
		cin >> l >> r >> v;
		ops.push_back({{l, r}, v});
		pre[l] += v;
		pre[r + 1] -= v;
		curr.insert(l);
		curr.insert(r + 1);
		while (!curr.empty() && pre[*curr.begin()] == 0) curr.erase(curr.begin());
		if (!curr.empty() && pre[*curr.begin()] < 0) {
			ans = i;
			cl();
		}
	}
	cl();
	for (long long i = 0; i <= ans; i++) {
		long long l = ops[i].first.first;
		long long r = ops[i].first.second;
		long long v = ops[i].second;
		pre[l] += v;
		pre[r + 1] -= v;
		curr.insert(l);
		curr.insert(r + 1);
	}

	long long run = 0;
	for (long long i = 1; i <= n; i++) {
		run += pre[i];
		cout << run + arr[i - 1] << " ";
	}
	cout << endl;
	cl();
	curr.clear();
	ops.clear();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}