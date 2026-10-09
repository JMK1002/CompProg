#include <bits/stdc++.h>
using namespace std;

#define int long long

const int b = 19;

int n;
int arr[300005];
int nxt[300005];
int prv[300005];
int mn[b][1000005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mn[0][i] = arr[i];
	}
	for (int i = 1, msk = 1; i < b; i++, msk <<= 1) {
		for (int j = 1; j <= n; j++) {
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + msk]);
		}
	}
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && arr[st.top()] <= arr[i]) {
			nxt[st.top()] = i - 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		nxt[st.top()] = n;
		st.pop();
	}

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && arr[st.top()] <= arr[i]) {
			prv[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		prv[st.top()] = 1;
		st.pop();
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int ptr = nxt[i];
		int run = 2e9;
		for (int j = b - 1, msk = 1 << (b - 1); j >= 0; j--, msk >>= 1) {
			// ! note stuff breaks if arr[i] can equal 0
			if (min(mn[j][ptr + 1], run) > arr[i]) {
				run = min(run, mn[j][ptr + 1]);
				ptr += msk;
			}
		}
		ans += min(n - i, ptr - nxt[i]) * (i - prv[i] + 1);
	}
	int s = 0;
	for (int i = 1; i <= n; i++) s += (n - i + 1) * i;
	cout << s - ans - n * (n + 1) / 2 << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		nxt[i] = 0;
		prv[i] = 0;
		for (int j = 0; j < b; j++) mn[j][i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
