#include <iostream>
#include <algorithm>
using namespace std;

long long n, x, y;
long long arr[200005];

void solve() {
	cin >> n >> x >> y;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (long long i = 0; i < n; i++) {
		arr[i] -= i;
		arr[i] = min(arr[i], y - i);
		if (i) arr[i] = max(arr[i - 1], arr[i]);
	}
	arr[n] = max(arr[n - 1], y - n);
	long long ans = 0;
	for (long long i = 0; i <= n; i++) {
		if (x >= arr[i]) continue;
		long long a = i - (n - i);
		if (a <= 0 && x + i < y) {
			ans = -1;
			break;
		}
		else if (a <= 0 && x + i >= y) {
			ans = 0;
			break;
		}
		long long k = (arr[i] - x) / a + ((arr[i] - x) % a != 0);
		x += a * k;
		ans += n * k;
	}
	if (ans != -1) ans += y - x;
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) {
		arr[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}