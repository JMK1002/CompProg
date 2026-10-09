#include <iostream>
using namespace std;

long long n;
long long arr[200];

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			long long diff = abs(arr[i] - arr[j]);
			ans = max(diff, ans);
		}
	}
	cout << ans << endl;
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}