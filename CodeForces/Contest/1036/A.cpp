#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int arr[104];
int barr[105];

void solve() {
	int n;
	cin >> n;
	bool works = false;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		barr[i] = arr[i];
		if (i != 0 && arr[i] < arr[i - 1]) {
			works = true;
		}
	}
	if (works) cout << "YES" << endl;
	else {
		cout << "NO" << endl;
		return;
	}
	sort(barr, barr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += arr[i] != barr[i];
	cout << cnt << endl;
	for (int i = 0; i < n; i++) if (arr[i] != barr[i]) cout << arr[i] << " ";
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