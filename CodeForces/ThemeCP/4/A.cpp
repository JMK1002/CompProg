#include <bits/stdc++.h>
using namespace std;

const long long MNINF = -2e13;

long long n, k;
string s;
bool known[200005];
long long arr[200005];
long long pre[200005];

void solve() {
	cin >> n >> k >> s;
	bool has = false;
	for (long long i = 1; i <= n; i++) {
		known[i] = (s[i - 1] == '1');
		has |= !known[i];
		cin >> arr[i];
		if (!known[i]) arr[i] = MNINF;
	}
	for (long long i = 1; i <= n; i++) pre[i] = arr[i] + pre[i - 1];
	long long mx = 0;
	long long mn = 0;
	for (long long i = 1; i <= n; i++) {
		mn = min(mn, pre[i]);
		mx = max(mx, pre[i] - mn);
	}
	if (mx > k || (!has && mx != k)) {
		cout << "NO" << endl;
		return;
	} 
	cout << "YES" << endl;
	mn = 0;
	long long i = 1;
	for (; i <= n && arr[i] != MNINF; i++) {
		mn = min(mn, pre[i]);
	}
	mx = pre[i] - mn;
	long long p = i;
	i++;
	for (; i <= n && arr[i] != MNINF; i++) {
		mx = max(mx, pre[i] - mn);
	}
	arr[p] += k - mx;
	for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
		for (long long i = 0; i <= n; i++) {
			arr[i] = 0;
			known[i] = false;
			pre[i] = 0;
		}
	}
	return 0;
}