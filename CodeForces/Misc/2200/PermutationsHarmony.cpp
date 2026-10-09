#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int n, k;

void solve() {
	cin >> n >> k;
	int fact[11];
	fact[0] = 1;
	if (n == 1 && k == 1) {
		cout << "YES" << endl << "1" << endl;
		return;
	}
	for (int i = 1; i <= 10; i++) fact[i] = fact[i - 1] * i;
	if (k % 2 == 1 && n % 2 == 0 || k == 1 || (n <= 10 && k > fact[n] - 3 * (k % 2))) {
		cout << "NO" << endl;
		return;
	}

	if (k % 2 == 0) {
		cout << "YES" << endl;
		vector<int> perm(n);
		iota(perm.begin(), perm.end(), 1);
		for (int i = 0; i < k / 2; i++) {
			for (int j : perm) cout << j << " ";
			cout << endl;
			for (int j : perm) cout << n - j + 1 << " ";
			cout << endl;
			next_permutation(perm.begin(), perm.end());
		}
	}
	else {
		cout << "YES" << endl;
		vector<int> perm(n), perm2, perm3;
		iota(perm.begin(), perm.end(), 1);		
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 0) perm2.push_back((n - (j - 1) / 2));
			else perm2.push_back(((n + 3) / 2 - j + (j - 1) / 2));
		}
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 1) perm3.push_back((n - (j - 1) / 2));
			else perm3.push_back(((n + 3) / 2 - j + (j - 1) / 2));
		}

		for (int j : perm) cout << j << " ";
		cout << endl;
		for (int j : perm2) cout << j << " ";
		cout << endl;
		for (int j : perm3) cout << j << " ";
		cout << endl;

		for (int i = 0; i < (k - 3) / 2; i++) {
			next_permutation(perm.begin(), perm.end());
			bool ah = false;
			bool temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != j + 1) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != n - j) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != perm2[j]) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != n + 1 - perm2[j]) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != perm3[j]) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			temp = true;
			for (int j = 0; j < n; j++) {
				if (perm[j] != n - perm3[j] + 1) {
					temp = false;
					break;
				}
			}
			ah |= temp;

			if (ah) {
				i--;
				continue;
			}
			for (int j : perm) cout << j << " ";
			cout << endl;
			for (int j : perm) cout << n - j + 1 << " ";
			cout << endl;
		}
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