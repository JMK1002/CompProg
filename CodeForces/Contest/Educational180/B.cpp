#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n;
int arr[1005];
int narr[1005];

void solve() {
	cin >> n;
	int ans = 1000000000;
	bool done = false;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		narr[i] = arr[i];
		if (i >= 1 && abs(arr[i - 1] - arr[i]) <= 1) {
			// cout << 0 << endl;
			done = true;
		}
	}
	if (done) {
		cout << 0 << endl;
		return;
	}
	reverse(narr, narr + n);
	// cout << is_sorted(arr, arr + n) << endl;
	if (!(is_sorted(arr, arr + n) || is_sorted(narr, narr + n))) {
		cout << 1 << endl;
		return;
	}
	cout << -1 << endl;
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