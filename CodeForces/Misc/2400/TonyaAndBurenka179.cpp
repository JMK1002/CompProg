#include <bits/stdc++.h>
using namespace std;

#define int long long

struct custom_hash {
    static unsigned long long splitmix64(unsigned long long x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    unsigned long long operator()(unsigned long long x) const {
        static const unsigned long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, q;
int arr[200005];
bool explored[200005];
vector<int> primes;
unordered_map<int, vector<int>, custom_hash> mp;
unordered_map<int, array<int, 2>, custom_hash> mx;

void sieve(int mx) {
	for (int i = 2; i <= mx; i++) {
		if (explored[i]) continue;
		primes.push_back(i);
		for (int j = i; j <= mx; j += i) explored[j] = true;
	}
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> divs;
	// for (int p : primes) {
	// 	if (p > n) break;
	// 	if (n % p != 0) continue;
	// 	divs.push_back(n / p);
	// }
	for (int i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		divs.push_back(i);
		if (i * i != n) divs.push_back(n / i);
	}
	sort(divs.begin(), divs.end());
	divs.pop_back();
	int ans = 0;
	for (int d : divs) {
		mp[d].assign(d, 0);
		mx[d][0] = 0;
		mx[d][1] = 0;
		for (int i = 0; i < d; i++) {
			int run = (i + d);
			mp[d][i] = arr[i];
			while (run != i) {
				mp[d][i] += arr[run];
				run += d;
				run %= n;
			}
			mp[d][i] *= d;
			if (mp[d][i] > mx[d][0]) {
				mx[d][1] = mx[d][0];
				mx[d][0] = mp[d][i];
			}
			else if (mp[d][i] > mx[d][1]) {
				mx[d][1] = mp[d][i];
			}
		}
		ans = max(ans, mx[d][0]);
	}

	cout << ans << endl;
	while (q--) {
		int ind, x;
		cin >> ind >> x;
		ind--;
		ans = 0;
		for (int d : divs) {
			if (mp[d][ind % d] == mx[d][0]) {
				mx[d][0] = mx[d][1];
				mx[d][1] = -1e9;
			}
			else if (mp[d][ind % d] == mx[d][1]) {
				mx[d][1] = -1e9;
			}

			mp[d][ind % d] -= d * arr[ind];
			mp[d][ind % d] += d * x;

			if (mp[d][ind % d] > mx[d][0]) {
				mx[d][1] = mx[d][0];
				mx[d][0] = mp[d][ind % d];
			}
			else if (mp[d][ind % d] > mx[d][1]) {
				mx[d][1] = mp[d][ind % d];
			}
			ans = max(ans, mx[d][0]);
		}
		arr[ind] = x;
		cout << ans << endl;
	}

	mp.clear();
	mx.clear();
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	sieve(200000);
	while (t--) {
		solve();
	}
	return 0;
}
