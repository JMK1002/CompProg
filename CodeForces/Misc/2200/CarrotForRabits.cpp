#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long arr[100005];
long long asdf[100005];

long long cnt(long long a, long long b) {
	long long x = a / b;
	return (a % b) * (x + 1) * (x + 1) + (b - a % b) * x * x;
}

void solve() {
	cin >> n >> k;
	long long ans = 0;
	set<pair<long long, long long>> st;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i] * arr[i];
		asdf[i] = 1;
		st.insert({cnt(arr[i], asdf[i] + 1) - cnt(arr[i], asdf[i]), i});
	}
	for (long long _ = 0; _ < k - n; _++) {
		pair<long long, long long> p = *st.begin();
		st.erase(st.begin());
		ans += p.first;
		long long i = p.second;
		asdf[i]++;
		st.insert({cnt(arr[i], asdf[i] + 1) - cnt(arr[i], asdf[i]), i});
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}