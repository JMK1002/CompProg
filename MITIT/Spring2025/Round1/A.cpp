#include <iostream>
using namespace std;

int n;

void solve() {
	cin >> n;
	if (n % 2 == 0) {
		cout << 2025;
		for (int i = 0; i < (n - 4); i++) cout << 0;
		cout << endl;
	}
	else {
		cout << 42025;
		for (int i = 0; i < (n - 5); i++) cout << 0;
		cout << endl;
	}
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