#include <iostream>
#include <set>
using namespace std;

int n;
int arr[1000005];

int op(int a, int b) {
	return a % b + b % a;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << 0 << " ";
	int mx = arr[0];
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= mx) ans = max(ans, op(arr[i], mx));
		else {
			if (mx * 2 > arr[i]) ans = arr[i];
			else {
				for (int j = 0; j < i; j++) ans = max(ans, op(arr[i], arr[j]));
			}
			mx = arr[i];
		}
		cout << ans << " ";
	}
	cout << endl;
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