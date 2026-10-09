#include <iostream>
using namespace std;

int n, m;
int k1, k2, k3, k4;
int cs, rs;
int c1, c2, r1, r2;

void solve() { 
	cin >> n >> m;

	cout << "SCAN 1 1" << endl;
	cout.flush();
	cin >> k1;

	cout << "SCAN " << n << " 1" << endl;
	cout.flush();
	cin >> k2;

	cs = (k1 + k2 + 6 - 2 * n) / 2;
	rs = (k1 - k2 + 2 + 2 * n) / 2;

	cout << "SCAN 1 " << cs / 2 << endl;
	cout.flush();
	cin >> k3;

	cout << "SCAN " << rs / 2 << " 1" << endl;
	cout.flush();
	cin >> k4;

	c1 = (k3 + 2 - rs + cs) / 2;
	r1 = (k4 + 2 - cs + rs) / 2;
	c2 = (-1 * (k3 + 2 - rs) + cs) / 2;
	r2 = (-1 * (k4 + 2 - cs) + rs) / 2;

	cout << "DIG " << r1 << " " << c1 << endl;
	cout.flush();
	bool b;
	cin >> b;
	if (b) {
		cout << "DIG " << r2 << " " << c2 << endl;
		cout.flush();
		cin >> b;
	}
	else {
		cout << "DIG " << r1 << " " << c2 << endl;
		cout.flush();
		cin >> b;

		cout << "DIG " << r2 << " " << c1 << endl;
		cout.flush();
		cin >> b;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}