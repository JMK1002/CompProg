#include <bits/stdc++.h>
using namespace std;

long long n;
string s;
long long pre[100005];
long long suff[100005];

void solve() {
	cin >> n >> s;
	s = "_" + s + "_";
	long long cnt = 0;
	long long run = 0;
	for (long long i = 1; i <= n; i++) {
		if (s[i] == s[i - 1]) cnt++;
		else cnt = 1;
		run += max(cnt - 2, 0ll);
		pre[i] = run;
	}
	reverse(s.begin(), s.end());
	cnt = 0;
	run = 0;
	for (long long i = 1; i <= n; i++) {
		if (s[i] == s[i - 1]) cnt++;
		else cnt = 1;
		run += max(cnt - 2, 0ll);
		suff[n - i + 1] = run;
	}
	reverse(s.begin(), s.end());
	long long ans = pre[n];
	for (long long i = 1; i <= n; i++) {
		long long l = i - 1;
		long long r = i + 1;
		while (l != 0 && s[l] != s[i]) l--;
		while (r != n + 1 && s[r] != s[i]) r++;
		ans = max(ans, pre[l] + suff[r] + max(0ll, (r - l - 1 - 1) * (r - l - 1 - 2) / 2));
	}
	cout << ans << endl;
	for (int i = 0; i <= n + 1; i++) {
		pre[i] = 0;
		suff[i] = 0;
	}
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