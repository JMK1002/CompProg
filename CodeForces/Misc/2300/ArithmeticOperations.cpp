#include <iostream>
#include <set>
#include <unordered_map>
#include <cstdint>
#include <stddef.h>
#include <chrono>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int sqrtm = 320;

int n;
int arr[100005];
int cnt[sqrtm * 100005];
unordered_map<int, int, custom_hash> dp[100005];
int ans = 1;

void solve() {
	for (int d = 0; d < sqrtm; d++) {
		for (int i = 0; i < n; i++) {
			ans = max(ans, ++cnt[arr[i] + i * d]);
		}
		for (int i = 0; i < n; i++) cnt[arr[i] + i * d] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= i + sqrtm && j < n; j++) {
			if ((arr[j] - arr[i]) % (j - i) != 0) continue;
			int d = (arr[j] - arr[i]) / (j - i);
			if (dp[i].find(d) == dp[i].end()) dp[j][d] = 2;
			else dp[j][d] = dp[i][d] + 1;
			ans = max(ans, dp[j][d]);
		}
		dp[i].clear();
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	solve();
	for (int i = 0; i < n; i++) {
		arr[i] *= -1;
	}
	solve();
	cout << n - ans << endl;
	return 0;
}