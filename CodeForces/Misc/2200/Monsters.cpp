#include <iostream>
using namespace std;

int n;
int arr[200005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
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