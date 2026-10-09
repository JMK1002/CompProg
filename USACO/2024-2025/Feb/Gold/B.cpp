#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bin(int l, int r){return 0;}

int mod = 1e9+7;

int n, m, q;
vector<int> ev;
vector<int> diff;
int pre[400005][2];

// ! EVERTHINTNG IS ONE INDEXED!!!

int val(int ind) {
	int cnt = upper_bound(ev.begin(), ev.end(), ind) - ev.begin();
	return cnt % 2;
}

// returns index of prev different element
int prev(int ind) {
	int cnt = upper_bound(ev.begin(), ev.end(), ind) - ev.begin();
	if (cnt == 0) return -1;
	return ev[cnt - 1];
}

// returns index of next different element
int nxt(int ind) {
	int cnt = upper_bound(ev.begin(), ev.end(), ind) - ev.begin();
	if (cnt == ev.size()) return -1;
	return ev[cnt];
}

int one(int l, int r) {
	int nl = (val(l) == 1) ? nxt(l) : l;
	int nr = (val(r) == 1) ? prev(r) : r;

	int il = upper_bound(ev.begin(), ev.end(), nl) - ev.begin();
	int ir = upper_bound(ev.begin(), ev.end(), nr) - ev.begin() - 1;
	return pre[ir][1] - (il - 1 < 0 ? 0 : pre[il - 1][1]) + (nl - l) + (r - nr);
}

int zero(int l, int r) {

}

int binpow(int a, int b) {
	int run = a;
	int res = 1;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;

		run *= run;
		run %= mod;
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		ev.push_back(l);
		ev.push_back(r + 1);
	}
	sort(ev.begin(), ev.end());
	vector<int> temp;
	for (int i = 0; i < ev.size(); i++) {
		if (!temp.empty() && temp[temp.size() - 1] == ev[i]) temp.pop_back();
		else temp.push_back(ev[i]);
	}
	ev = temp;
	for (int i = 0; i < ev.size() - 1; i++) diff.push_back(ev[i + 1] - ev[i]);
	for (int i = 0; i <= diff.size(); i++) {
		pre[i][1] = ((i == 0) ? 0 : pre[i - 1][1]) + diff[i] * (i % 2 == 0);
	}
	for (int i = 1; i <= diff.size(); i++) {
		pre[i][0] = pre[i - 1][0] + diff[i] * (i % 2 == 1);
	}
	cout << (one(-10, 100)) << endl;

	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;

		int d = k - one(l, r); // amount of zeros in final num
		if (d <= 0) {
			cout << (binpow(2, k) - 1 + mod) % mod << endl;
			continue;
		}

		int low = l; // inclusive
		int high = r + 1; // exclusive
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (zero(mid, r) < k) {
				high = mid;
			}
			else if (zero(mid, r) > k) {
				low = mid;
			}
			else {
				low = mid;
				high = mid;
			}
		}
		int len = r - low + 1;

		// TODO ADD MOD STUFF CUZ WILL OVERFLOW
		cout << bin(low, r) + binpow(2, len) * binpow(2, k - len);
	}
	return 0;
}