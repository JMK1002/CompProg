#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	if ((arr[0] + arr[n - 1]) % 2 == 0) {
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != arr[0] % 2) {
			ans = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] % 2 != arr[n - 1] % 2) {
			ans = min(ans, n - 1 - i);
			break;
		}
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}