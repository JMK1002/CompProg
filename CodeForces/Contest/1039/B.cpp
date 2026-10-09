#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int l = 0;
	int r = n - 1;
	for (int i = 0; i < n; i++) {
		if ((arr[l] > arr[r]) ^ (i % 2 == 0)) {
			cout << "L";
			l++;
		}
		else {
			cout << "R";
			r--;
		}
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