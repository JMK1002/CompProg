#include <bits/stdc++.h>
using namespace std;

int n;
int arr[102];

void solve() {
	cin >> n;
	int cnt = 0;
	vector<int> cnts;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0 || arr[i - 1] == arr[i]) {
			cnt++;
		}
		else {
			cnts.push_back(cnt);
			cnt = 1;
		}
	}
	cnts.push_back(cnt);
	sort(cnts.begin(), cnts.end());
	reverse(cnts.begin(), cnts.end());
	int ans = 0;
	for (int i = 0; i < cnts.size(); i++) {
		ans = max(ans, cnts[i] * (i + 1));
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}