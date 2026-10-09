#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

long long n;
pair<long long, long long> arr[500005];

void solve() {
	cin >> n;
	for (long long i = 0; i <= n; i++) arr[i] = {0, 0};
	for (long long i = 0; i < n; i++) cin >> arr[i].second;
	for (long long i = 0; i < n; i++) {
		long long s;
		cin >> s;
		arr[i].first = s - arr[i].second;
	}
	sort(arr, arr + n);
	long long unused = 0;
	for (long long i = 0; i < n; i++) {
		if (arr[i].first - unused <= 0) {
			unused += arr[i].second;
		}
		else {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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