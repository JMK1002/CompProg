#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[200005];
int b[200005];
int preMin[200005];
int suffMax[200005];

int test(int i1, int i2) {
	swap(a[i1], a[i2]);
	int ap = 0;
	int bp = 0;
	for (int i = 0; i < n; i++) {
		if (a[ap] > b[bp]) ap++;
		else bp++;
	}
	swap(a[i1], a[i2]);
	return ap;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	preMin[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[preMin[i - 1]]) preMin[i] = i;
		else preMin[i] = preMin[i - 1];
	}
	suffMax[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[suffMax[i + 1]]) suffMax[i] = i;
		else suffMax[i] = suffMax[i + 1];
	}

	int low = 0;
	int high = n + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		if (test(mid == 0 ? suffMax[mid] : preMin[mid - 1], suffMax[mid]) >= mid) low = mid;
		else high = mid;
	}
	cout << max(low, test(0, 0)) << endl;

	for (int i = 0; i <= n; i++) {
		a[i] = 0;
		b[i] = 0;
		preMin[i] = 0;
		suffMax[i] = 0;
	}
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