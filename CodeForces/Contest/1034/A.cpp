#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	n %= 4;
	if (n == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}