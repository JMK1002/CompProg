#include <bits/stdc++.h>
using namespace std;

long long n, s, x;
long long arr[200005];
long long pre[200005];
map<long long, vector<long long>> inds;

void solve() {
	cin >> n >> s >> x;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = arr[i] + pre[i - 1];
	}
	long long gPrev = -1;
	long long ePrev = -1;
	long long ans = 0;
	for (long long i = 0; i <= n; i++) {
		if (arr[i] > x) gPrev = i;
		else if (arr[i] == x) ePrev = i;
		long long tgt = pre[i] - s;
		long long cnt = upper_bound(inds[tgt].begin(), inds[tgt].end(), ePrev - 1) - lower_bound(inds[tgt].begin(), inds[tgt].end(), gPrev);
		ans += max(0ll, cnt);
		inds[pre[i]].push_back(i);
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		pre[i] = 0;
	}
	inds.clear();
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