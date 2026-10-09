#include <iostream>
#include <set>
using namespace std;

int n, k;
set<int> children[1002];
int arr[1002];
int par[1002];

void replace(int a, int b) {
	for (int i = 1; i <= n; i++) {
		if (children[i].find(a) != children[i].end()) {
			children[i].erase(a);
			children[i].insert(b);
		}
	}
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) cin >> arr[j];
		for (int j = 0; j < n; j += 2) {
			children[arr[j + 1]].insert(arr[j]);
		}
	}
	for (int i = 1; i <= n; i++) par[i] = -1;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (children[i].size() == 2) {
				int c1 = *children[i].begin();
				int c2 = *++children[i].begin();
				par[c1] = i;
				par[c2] = i;
				replace(c1, i);
				replace(c2, i);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << par[i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

// 2 4 3 5 1
// 1 5 2 4 3
// 1 5 2 4 3
// 1 5 2 4 3
// 1 5 3 4 2
// 1 5 3 4 2
// 1 5 3 4 2
// 1 5 3 4 2
// 1 5 3 4 2
// 3 4 2 5 1
// 2 4 3 5 1
// 1 5 2 4 3
// 3 4 2 5 1
// 2 4 3 5 1
// 2 4 3 5 1
// 1 5 2 4 3
// 3 4 2 5 1
// 3 4 2 5 1
// 1 5 2 4 3
// 2 4 3 5 1
// 1 5 2 4 3
// 1 5 3 4 2
// 3 4 2 5 1
// 1 5 3 4 2
// 1 5 2 4 3
// 1 5 3 4 2
// 1 5 2 4 3
// 2 4 3 5 1
// 2 4 3 5 1
// 2 4 3 5 1
// 2 4 3 5 1
// 2 4 3 5 1
// 1 5 2 4 3
// 1 5 3 4 2
// 1 5 2 4 3
// 3 4 2 5 1
// 1 5 3 4 2
// 3 4 2 5 1
// 3 4 2 5 1
// 1 5 2 4 3
// 2 4 3 5 1
// 1 5 2 4 3
// 1 5 3 4 2
// 2 4 3 5 1
// 2 4 3 5 1
// 1 5 2 4 3
// 1 5 2 4 3
// 1 5 2 4 3
// 1 5 2 4 3
// 1 5 2 4 3
// 3 4 2 5 1
// 3 4 2 5 1
// 3 4 2 5 1
// 1 5 2 4 3
// 1 5 3 4 2
// 1 5 3 4 2
// 2 4 3 5 1
// 3 4 2 5 1
// 1 5 2 4 3
// 3 4 2 5 1