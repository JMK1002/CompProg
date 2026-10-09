#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, a;
string s;
int arr[50004];
int dist[100000];
bool explored[100000];
set<pair<int, int>> adj[100004];
int dists[700][100004];

void djikstra(int v, int basdf) {
	for (int i = 0; i <= n + a + 10; i++) {
		dist[i] = 1000000000;
		explored[i] = false;
	}
	set<pair<int, int>> q;
	dist[v] = 0;
	explored[v] = true;
	q.insert({dist[v], v});
	while (!q.empty()) {
		pair<int, int> p = *q.begin();
		q.erase(q.begin());
		explored[p.second] = true;
		for (pair<int, int> e : adj[p.second]) {
			if (dist[p.second] + e.second < dist[e.first] && !explored[e.first]) {
				q.erase({dist[e.first], e.first});
				dist[e.first] = dist[p.second] + e.second;
				q.insert({dist[e.first], e.first});
			}
		}
	}
	for (int i = 0; i <= n + a + 10; i++) {
		dists[basdf][i] = dist[i];
	}
	// dists[i] = dist;
}

void addEdge(int u, int v, int w) {
	adj[u].insert({v, w});
	adj[v].insert({u, w});
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> s;
	// for (int i = 0; i < 50000; i++) s += "a";
	n = s.size() - 1;
	a = 26 * 26;
	for (int i = 0; i < n; i++) {
		arr[i] = (s[i] - 'a') * 26 + (s[i + 1] - 'a' + 1);
		addEdge(i, arr[i] + n, 1);
	}
	for (int i = 0; i < n - 1; i++) {
		addEdge(i, i + 1, 2);
	}

	for (int i = 1; i <= a; i++) {
		djikstra(i + n, i);
	}

	int q;
	cin >> q;
	// q = 50000;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		// u = 1; v = 40000;
		int ans = abs(u - v);
		for (int i = 1; i <= a; i++) {
			ans = min(ans, (dists[i][u] + dists[i][v]) / 2);
		}
		cout << ans << endl;
	}
	return 0;
}