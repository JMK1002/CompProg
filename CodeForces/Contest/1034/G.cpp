#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, q;
int arr[200005];
vector<int> divs;
map<int, int> incs;

void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i * i <= m; i++) {
		if (m % i != 0) continue;
		divs.push_back(i);
		if (m / i != i) divs.push_back(m / i);
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j : divs) {
			incs[j] += (i != 0 && arr[i - 1] % j > arr[i] % j);
		}
	}

	while (q--) {
		int a;
		cin >> a;
		if (a == 1) {
			int i, v;
			cin >> i >> v;
			i--;
			int old = arr[i];
			for (int j : divs) {
				arr[i] = old;
				if (i != 0) incs[j] -= (arr[i - 1] % j > arr[i] % j);
				if (i != n - 1) incs[j] -= (arr[i] % j > arr[i + 1] % j);
				arr[i] = v;
				if (i != 0) incs[j] += (arr[i - 1] % j > arr[i] % j);
				if (i != n - 1) incs[j] += (arr[i] % j > arr[i + 1] % j);
			}
		}
		else {
			int k;
			cin >> k;
			k = __gcd(k, m);
			cout << (incs[k] >= m / k ? "No" : "Yes") << endl;
		}
	}

	divs.clear();
	incs.clear();
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