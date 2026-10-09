#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100005];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cout << arr[k + (n - k) / 2] - arr[(n - k - 1) / 2] + 1 << endl;
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