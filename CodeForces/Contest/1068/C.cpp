#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[200005];

void solve() {
	cin >> n >> k;
	set<int> st, ans;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// arr[i] = i + 1;
		st.insert(arr[i]);
		ans.insert(arr[i]);
	}
	bool works = true;
	for (int i : st) {
		if (ans.find(i) == ans.end()) {
			continue;
		}
		for (int j = i; j <= k; j += i) {
			if (st.find(j) == st.end()) {
				works = false;
				break;
			}
			else if (j != i) {
				ans.erase(j);
			}
		}
		if (!works) break;
	}
	if (!works) {
		cout << -1 << endl;
	}
	else {
		cout << ans.size() << endl;
		for (int i : ans) cout << i << " ";
		cout << endl;
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