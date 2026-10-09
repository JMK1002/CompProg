#include <iostream>
using namespace std;

int n;
string s1, s2;
int cnt[2];

void solve() {
	cin >> n >> s1 >> s2;
	cnt[0] = 0;
	cnt[1] = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] == '1') cnt[i % 2]++;
		if (s2[i] == '1') cnt[(i + 1) % 2]++;
	}

	if (cnt[0] <= n / 2 && cnt[1] <= (n - n / 2)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}