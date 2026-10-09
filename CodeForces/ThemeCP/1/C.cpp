#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[400005];
long long b[400005];
set<pair<long long, long long>> vals;

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	for (long long i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}
	long long ans = 0;
	vals.insert({0, 0}); // val, index
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		sum += arr[i];
		while (!vals.empty() && vals.begin()->second < i) vals.erase(vals.begin());
		if (vals.empty()) break;
		long long amnt = vals.begin()->first;
		ans = max(sum - amnt, ans);
		vals.insert({arr[i] + amnt, b[i]});
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		b[i] = 0;
	}
	vals.clear();
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