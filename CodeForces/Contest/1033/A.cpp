#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

void solve() {
	int l1, b1, l2, b2, l3, b3;
	cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
	if ((l1 == l2 && l2 == l3 && (l1 == b1 + b2 + b3) ||
		l1 == l2 + l3 && b2 == b3 && b2 + b1 == l1)) {
		cout << "YES" << endl;
		return;
	}
	swap(l1, b1);
	swap(l2, b2);
	swap(l3, b3);
	if ((l1 == l2 && l2 == l3 && (l1 == b1 + b2 + b3) ||
		l1 == l2 + l3 && b2 == b3 && b2 + b1 == l1)) {
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
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