#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int v, c, f;
	edge() {};
	edge(int v, int c, int f) : v(v), c(c), f(f) {};
};

int n, m;
set<int> adj[1000];
vector<edge> edges;

int edmondKarp() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int e : adj[v]) {
			if (edges[e].f - edges[e].c == 0) continue;
			
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		adj[u].insert(edges.size());
		edges.push_back(edge(v, c, 0));
		adj[v].insert(edges.size());
		edges.push_back(edge(u, 0, 0));
	}


	return 0;
}