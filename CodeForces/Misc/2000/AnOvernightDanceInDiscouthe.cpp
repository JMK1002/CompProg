#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> pos[1005];
long long r[1005];
long long over[1005];

void solve() {
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> pos[i].first >> pos[i].second;
		cin >> r[i];
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			if (i == j) continue;
			long long dx = abs(pos[i].first - pos[j].first);
			long long dy = abs(pos[i].second - pos[j].second);
			if (dx * dx + dy * dy <= r[i] * r[i] && r[i] > r[j]) over[j]++;
		}
	}
	long long ans = 0;
	long double pi = 3.141592653589793238462643383279502884197169399375105820974944;
	for (long long i = 0; i < n; i++) {	
		if (over[i] == 0 || over[i] % 2 == 1) ans += r[i] * r[i];
		else ans -= r[i] * r[i];
	}
	cout << ans * pi << endl;

}

int main() {
	cout.precision(20);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}