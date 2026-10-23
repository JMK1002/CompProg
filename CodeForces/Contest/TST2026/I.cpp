#include <bits/stdc++.h>
using namespace std;

#define int long long

int primes[10000005];
vector<int> primeLst;
vector<int> lst;

int n, l, r;

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		b >>= 1;
	}
	return res;
}

void determineNums(vector<int>& poweredNums, int ind, int val, vector<int>& nums) {

}

void solve() {
	cin >> n >> l >> r;
	if (n == 1) {
		cout << r - l + 1 << endl;
		return;
	}
	else if (n == 2) {
		cout << (r - l + 1) * (r - l) << endl;
		return;
	}
	else if (n >= 30) {
		cout << 0 << endl;
		return;
	}
	n--;
	for (int i = l; i <= r; i++) {
		map<int, int> facts;
		int x = i;
		while (x != 1) {
			facts[primes[x]]++;
			x /= primes[x];
		}
		vector<int> denoms;
		for (auto p : facts) {
			if (p.second >= n) {
				int x = 1;
				denoms.push_back(binpow(p.first, n));
			}
		}

		vector<int> poweredNums;
		for (int l : lst) {
			int x = binpow(l, n);
			if (x > 1e9) break;
			poweredNums.push_back(x);
		}

		vector<int> nums;
		determineNums(poweredNums, 0, 1, nums);

		for (int msk = 0; msk < (1 << denoms.size()); msk++) {
			int denom = 1;
			for (int j = 0, run = 1; j < denoms.size(); j++, run <<= 1) {
				if (msk & j) denom *= denoms[j];
			}
			int num = i / denom;

		}
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	for (int i = 2; i <= 10000004; i++) {
		if (primes[i]) continue;
		primeLst.push_back(i);
		for (int j = i * 2; j <= 10000004; j += i) primes[j] = i;
	}
	for (int i = 1; i <= 30; i++) {
		for (int p : primeLst) {
			int x = binpow(p, i);
			if (x >= 1e9) break;
			lst.push_back(x);
		}
	}
	sort(lst.begin(), lst.end());
	int t=1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
