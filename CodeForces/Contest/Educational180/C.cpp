#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

long long n;
long long arr[5005];

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	long long mx = arr[n - 1];
	long long ans = 0;
	for (long long i = 1; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			long long v = max(mx - arr[i] - arr[j], arr[j] - arr[i]) + 1;
			ans += i - (lower_bound(arr, arr + i, v) - arr);
		}
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}