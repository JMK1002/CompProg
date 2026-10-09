#include <iostream>
using namespace std;

int n;
int arr[200];

void solve() {
	cin >> n;
	int cnt = 0;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt += arr[i];
		if (i != 0 && arr[i - 1] == arr[i] && arr[i] == 0) {
			ans = false;
		}
	}
	if (cnt < (n - 1) / 2 + (n - 1) % 2 || cnt == n) ans = false;
	if (!ans) cout << "YES" << endl;
	else cout << "NO" << endl; 
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