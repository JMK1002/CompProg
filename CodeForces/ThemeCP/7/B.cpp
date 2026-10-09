#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, k;
int arr[100005];
int brr[100005];
char chars[12];
int pw[12];

void solve() {
	cin >> n >> k >> a >> b;
	map<char, int> mp;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (!mp[a[i]]) {
			chars[cnt] = a[i];
			mp[a[i]] = cnt++;
		}
		arr[i] = mp[a[i]];
		brr[i] = mp[b[i]];
	}
	cnt--;
	k = min(k, cnt);
	long long ans = 0;
	for (int j = 0; j < (1 << (cnt)); j++) {
		if (__builtin_popcount(j) != k) continue;

		long long temp = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == brr[i] || (pw[arr[i] - 1] & j)) {
				temp += ++cnt;
			}
			else {
				cnt = 0;
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < 11; i++) pw[i] = 1 << i;
	while (t--) {
		solve();
	}
	return 0;
}