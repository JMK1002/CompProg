#include <iostream>
#include <set>
using namespace std;

const int mod = 998244353;

int n, s;
int a[200005];
int b[200005];
bool taken[200005];

void solve() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++) b[i] = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == -1) continue;
		b[x] = i;
		taken[i] = true;
	}

	int cnt = 0;
	long long ans = 1;
	set<int> curr;
	for (int i = 1; i <= s; i++) {
		if (!taken[a[i]]) cnt++;
		else curr.insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (s + i <= n && !taken[a[s + i]]) cnt++;
		else if (s + i <= n) curr.insert(a[s + i]);

		if (b[i] == -1) ans *= cnt;
		else if (curr.find(b[i]) == curr.end()) ans = 0;

		if (b[i] == -1) cnt--;
		else curr.erase(b[i]);

		ans %= mod;
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		a[i] = 0;
		b[i] = 0;
		taken[i] = false;
	}
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