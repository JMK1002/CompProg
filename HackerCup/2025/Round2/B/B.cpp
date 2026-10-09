#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000005];
int b[1000005];
int amnt[1000005];

bool works(int pre) {
	int cnt = 0;
	for (int i = pre; i < n; i++) {
		if (i == pre || a[i] != a[i - 1]) {
			cnt++;
			amnt[cnt] = n - 1 - i + 1;
		}
	}
	int ptr = 0;
	int cnt2 = 0;
	int i = 1;
	while (i <= cnt && ptr < m) {
		if (cnt2 == amnt[i]) {
			i++;
			cnt2 = 0;
		}
		else if (b[ptr] < amnt[i] - cnt2) {
			cnt2 += b[ptr];
			ptr++;
		}
		else { 
			if (amnt[i] == 1000) {
				int x = 1;
			}
			cnt2 = min(b[ptr] - (amnt[i] - cnt2), min(cnt2, amnt[i + 1]));
			i++;
			ptr++;
		}
	}
	if (cnt2 == amnt[i]) {
		i++;
		cnt2 = 0;
	}
	for (int k = 0; k <= cnt + 1; k++) amnt[k] = 0;
	if (ptr == m && i < cnt + 1) return false;
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);
	int low = 0; // check if works
	int high = n;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (works(mid)) high = mid;
		else low = mid;
	}
	if (works(0)) cout << n << endl;
	else {
		while (high < n && a[high - 1] == a[high]) high++;
		cout << n - high << endl;
	}

	for (int i = 0; i <= n; i++) a[i] = 0;
	for (int i = 0; i <= m; i++) b[i] = 0;
}

int main() {
	// ulimit -s unlimited
	// 7z e <MyFile>.zip
	freopen("defining_prizes_validation_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int __ = 1;
	while (t--) {
		cout << "Case #" << __ << ": ";
		solve();
		__++;
	}
	return 0;
}
// 7 6
// 10 11 25 9 9 9 11
// 2 2 2 2 2 2
// 5 1
// 1 2 3 4 5
// 10000
// 5 4
// 2 3 5 7 11
// 100 100 100 100
// 12 14
// 43 51 95 22 11 2 49 55 22 51 88 13
// 30 29 40 19 50 12 45 60 24 9 12 45 38 12
// 11 10
// 43 51 95 22 11 2 49 55 88 13 0
// 100 100 100 100 100 100 100 100 100 100
// 10 10
// 58 234 95 23 8954 345 234 238 54 235
// 1 1 1 1 1 1 1 1 1 1