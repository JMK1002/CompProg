#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[300005];
int pre[300005];
pair<int, int> asdf;

bool check(int v) {
	pre[0] = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1];
		if (arr[i] >= v) pre[i]++;
		else if (arr[i] < v) pre[i]--;
	}
	int run = 0;
	for (int i = k; i <= n; i++) {
		if (pre[i - k] < pre[run]) {
			run = i - k;
		}

		if (pre[i] - pre[run] >= 0) {
			asdf = {run+1, i};
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int low = 0;
	int high = n + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (check(mid)) low = mid;
		else high = mid;
	}
	check(low);
	cout << low << " " << asdf.first << " " << asdf.second << endl;
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