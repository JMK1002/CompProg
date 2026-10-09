#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1 + (arr[i] != arr[n - 1]);
		int	r = n - 1;
		while (true) {
			int ind = upper_bound(arr + i, arr + n, (arr[i] + arr[r]) / 2) - arr - 1;
			if (arr[i] == arr[ind]) {
				cnt += ind - i;
				break;
			}
			r = ind;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << n - ans << endl;
	for (int i = 0; i <= n; i++) arr[i] = 0;
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