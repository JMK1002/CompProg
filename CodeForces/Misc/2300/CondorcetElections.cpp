#include <iostream>
using namespace std;

int n, m;

void addEdge(int a, int b) {
	for (int i = 1; i <= n; i++) {
		if (i == a || i == b) continue;
		cout << i << " ";
	}
	cout << a << " " << b << endl;
	cout << a << " " << b << " ";
	for (int i = n; i >= 1; i--) {
		if (i == a || i == b) continue;
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	cin >> n >> m;
	cout << "YES" << endl;
	cout << 2 * m << endl;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	return 0;
}