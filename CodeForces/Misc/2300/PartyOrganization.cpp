#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool adj[52][52];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u >= 50 || v >= 50) continue;
		adj[u][v] = true;
		adj[v][u] = true;
	}

	for (int a = 1; a <= min(46, n); a++) {
		for (int b = a + 1; b <= min(46, n); b++) {
			for (int c = b + 1; c <= min(46, n); c++) {
				for (int d = c + 1; d <= min(46, n); d++) {
					for (int e = d + 1; e <= min(46, n); e++) {
						bool asdf = adj[a][b];
						vector<int> v = {a, b, c, d, e};
						bool works = true;
						for (int i : v) {
							for (int j : v) {
								if (i == j) continue;
								if (adj[i][j] != asdf) {
									works = false;
									break;
								}
							}
							if (!works) break;
						}
						if (works) {
							for (int i : v) {
								cout << i << " ";
							}
							cout << endl;
							return;
						}
					}
				}
			}
		}
	}
	cout << -1 << endl;
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