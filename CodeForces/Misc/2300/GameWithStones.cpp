#include <bits/stdc++.h>
using namespace std;

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

// unordered_map<int, int, custom_hash>

int n;
int arr[300005];
int pre[300005];
unordered_map<int, vector<int>, custom_hash> inds[2];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = arr[i] - pre[i - 1];
		inds[i % 2][pre[i]].push_back(i);
	}

	set<pair<int, int>> st[2]; // (looking at index - i) % 2
	st[0].insert({1e9, n + 1});
	st[1].insert({1e9, n + 1});
	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		bool j = i % 2;
		while (!st[j].empty() && -pre[i] > st[j].begin()->first) st[j].erase(st[j].begin());
		st[j].insert({-pre[i], i});
		int bound = min(st[j].lower_bound({pre[i - 1], 1e9})->second, st[!j].lower_bound({-pre[i - 1], 1e9})->second);
		ans += lower_bound(inds[j][-pre[i - 1]].begin(), inds[j][-pre[i - 1]].end(), bound) - lower_bound(inds[j][-pre[i - 1]].begin(), inds[j][-pre[i - 1]].end(), i);
		ans += lower_bound(inds[!j][pre[i - 1]].begin(), inds[!j][pre[i - 1]].end(), bound) - lower_bound(inds[!j][pre[i - 1]].begin(), inds[!j][pre[i - 1]].end(), i);
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		pre[i] = 0;
	}
	inds[0].clear();
	inds[1].clear();
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