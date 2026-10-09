#include <iostream>
#include <vector>
using namespace std;

int n;
string s;

void solve() {
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) cnt += s[i] == '1';
	if (cnt % 2 == 1) {
		cout << -1 << endl;
		return;
	}
	vector<int> ans;
	bool lst = false;
	for (int i = 0; i < 2 * n; i += 2) {
		if (s[i] == s[i + 1]) continue;
		if ((s[i] - '0') == lst) {
			ans.push_back(i+1);
		}
		else {
			ans.push_back(i+2);
		}
		lst = !lst;
	} 
	cout << ans.size() << " ";
	for (int i : ans) cout << i << " ";
	cout << endl;
	for (int i = 1; i <= 2 * n; i+=2) cout << i << " ";
	cout << endl;
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