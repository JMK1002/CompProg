#include <iostream>
#include <algorithm>
using namespace std;

int n, q;
int arr[200005];
int pre[200005];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	pre[0] = arr[0] + 1;
	long long s = arr[0];
	for (int i = 1; i < n; i++) {
		pre[i] = min(arr[i] + 1, pre[i - 1] + 1);
		s += arr[i];
	}

	while (q--) {
		int k;
		cin >> k;

		// for (int i = 0; i < min(k, n - ((k % 2) ^ (n % 2))); i++) {
		// 	temp[i] += k - i;
		// }
		int amnt = min(k, n - ((k % 2) ^ (n % 2)));
		int sub = (k - min(k, n - ((k % 2) ^ (n % 2)))) / 2;

		long long sum = s + (long long) k * (k + 1) / 2 - (long long) (k - amnt) * (k - amnt + 1) / 2;
		long long mn = (amnt - 1 < 0) ? arr[0] : min((long long) pre[amnt - 1] + (k - amnt), (amnt == n) ? (long long) 1e16 : arr[amnt]);

		cout << min(mn, (sum - sub) / n) << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}