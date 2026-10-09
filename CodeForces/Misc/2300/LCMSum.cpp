#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, r;
vector<int> divs[200005];

void solve() {
	cin >> l >> r;
	long long cnt = 0;

	for (int i = l; i <= r; i++) {
		long long x = lower_bound(divs[i].begin(), divs[i].end(), i) - lower_bound(divs[i].begin(), divs[i].end(), l);
		cnt += x * (x - 1) / 2;
	}

	for (int k = l; k <= r; k++) {
		if (k % 3 != 0) continue;
		int j = 2 * k / 3;
		cnt += (2 * k % 4 == 0 && k / 2 >= l) + (2 * k % 5 == 0 && k / 5 * 2 >= l);
	}
	long long n = r - l + 1;
	cout << n * (n - 1) * (n - 2) / 6 - cnt << endl;
}

int main() {
	int t;
	cin >> t;

	for (int i = 1; i < 200005; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j != 0) continue;
			divs[i].push_back(j);
			if (j * j != i) divs[i].push_back(i / j);
		}
		sort(divs[i].begin(), divs[i].end());
	}

	while (t--) {
		solve();
	}
	return 0;
}