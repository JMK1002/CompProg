#include <bits/stdc++.h>
using namespace std;

#define int long long

int arr[300005];
int prv[300005];

void solve() {
	int n;
	cin >> n;
	stack<int> st;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (!st.empty() && arr[st.top()] != arr[i] - 1) st.pop();
		if (st.empty()) prv[i] = -1;
		else prv[i] = st.top();
		st.push(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (i - prv[i]) * (n - i);
	}
	cout << ans << endl;
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
