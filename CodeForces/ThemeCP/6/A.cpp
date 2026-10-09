#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int pre[100005];
string s;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = arr[i] ^ pre[i - 1];
	}
	cin >> s;

	int z = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0') z ^= arr[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 1) {
			int l, r;
			cin >> l >> r;
			z ^= pre[r] ^ pre[l - 1];
		}
		else {
			int v;
			cin >> v;
			if (v == 0) cout << z << " ";
			else cout << (z ^ pre[n]) << " ";
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = 0;
		pre[i] = 0;
	}
	cout << endl;
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