#include <iostream>
#include <string>
using namespace std;

int n;

int doOp(string s) {
	cout << s << endl;
	cout.flush();
	int b;
	cin >> b;
	return b;
}

void solve() {
	cin >> n;
	doOp("mul 9");
	doOp("digit");
	doOp("digit");
	if (n != 9) doOp("add " + to_string(n - 9));
	doOp("!");
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