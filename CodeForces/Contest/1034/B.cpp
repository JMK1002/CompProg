#include <iostream>
using namespace std;

int n, j, k;
int arr[200005];

void solve() {
	cin >> n >> j >> k;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(arr[i], mx);
	}
	if (k != 1 || (k == 1 && arr[j - 1] == mx)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}