#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, k;
int arr[100005];
multiset<int> a;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		a.insert(arr[i]);
	}
	int groups = 0;
	while (!a.empty()) {
		if (a.size() == 1) {
			a.clear();
			groups++;
			continue;
		}

		auto f = a.begin();
		auto sec = ++a.begin();
		auto l = --a.end();
		
		if (*f >= k || a.size() == 1) {
			a.erase(f);
			groups++;
			continue;
		}
		else if (*f + *sec >= k || a.size() == 2) {
			a.erase(a.begin());
			a.erase(--a.end());
			groups++;
			continue;
		}
		else {
			auto m = --a.lower_bound(k - *f);
			a.erase(m);
			a.erase(a.begin());
			a.erase(--a.end());
			groups++;
			continue;
		}
	}
	cout << groups - 1 << endl;
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