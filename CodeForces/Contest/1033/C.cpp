#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

long long n, m;

void solve() {
	cin >> n >> m;
	if (m < n || m > n * (n + 1) / 2) {
		cout << -1 << endl;
		return;
	}

	vector<long long> ans;
	vector<bool> explored(n + 1);
	long long initN = n;
	while (true) {
		if (m == n) {
			ans.push_back(1);
			explored[1] = true;
			break;
		}
		else if (m < 2 * n - 1) {
			ans.push_back(m - (n - 1));
			explored[m - (n - 1)] = true;
		}
		else {
			ans.push_back(n);
			explored[n] = true;
		}
		n--;
		m -= ans.back();
	}
	cout << ans[0] << endl;
	for (long long i = 1; i <= initN; i++) if (!explored[i]) ans.push_back(i);

	for (long long i = 0; i < initN - 1; i++) {
		cout << ans[i] << " " << ans[i + 1] << endl;
	}
	
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}