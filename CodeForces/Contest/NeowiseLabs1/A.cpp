#include <iostream>
#include <vector>
using namespace std;

int n;
string s;

void solve() {
	cin >> n >> s;
	int low = -1;
	int high = 1;
	vector<int> ans;
	ans.push_back(0);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '<') {
			ans.push_back(low);
			low--;
		}
		else {
			ans.push_back(high);
			high++;
		}
	}
	for (int i : ans) cout << i - low << " ";
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