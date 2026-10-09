#include <iostream>
#include <set>
using namespace std;

int n;
int arr[200005];
int suff[200005];
set<int> vals;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = max(arr[i], suff[i + 1]);
	}
	int mn = 1000000000;
	for (int i = 0; i < n - 1; i++) {
		mn = min(mn, arr[i]);
		int mx = suff[i + 1];
		vals.insert(mn);
		vals.insert(mx);
	}
	for (int i = 0; i < n; i++) {
		if (vals.find(arr[i]) != vals.end()) cout << 1;
		else cout << 0;
	}
	cout << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		suff[i] = 0;
	}
	vals.clear();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}