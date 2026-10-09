#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
	int a, x, y;
	cin >> a >> x >> y;
	if ((x < a && a < y) || (y < a && a < x)) {
		cout << "NO" << endl;
		return;
	} 
	cout << "YES" << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}