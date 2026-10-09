#include <iostream>
#include <vector>
using namespace std;

int n;
string a, b;
vector<int> ans;

void shift(string & x, int amnt) {
	string res;
	for (int i = 0; i < n; i++) {
		if (i + amnt < n && i + amnt >= 0) res += x[i + amnt];
		else res += '0';
	}
	x = res;
}

void combine(string & x, string & y) {
	for (int i = 0; i < n; i++) {
		x[i] = (x[i] != y[i]) + '0';
	}
}

void op(string & x, int amnt) {
	string temp = x;
	shift(temp, amnt);
	combine(x, temp);
}

void solve() {
	cin >> n >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return;
	}
	int msa = -1;
	int msb = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] == '1') msb = i;
		if (a[i] == '1') msa = i;
	}
	if (msb == -1 || msa == -1) {
		cout << -1 << endl;
		return;
	}

	if (a[msb] == '0') {
		ans.push_back(msa - msb);
		op(a, msa - msb);
		msa = min(msa, msb);
	}
	
	for (int i = msb + 1; i < n; i++) {
		if (a[i] != b[i]) {
			ans.push_back(msa - i);
			op(a, msa - i);
		}
	}
	int la = -1;
	for (int i = 0; i < n; i++) if (a[i] == '1') la = i;

	for (int i = msb - 1; i >= 0; i--) {
		if (a[i] != b[i]) {
			ans.push_back(la - i);
			op(a, la - i);
		}
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;
	ans.clear();
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