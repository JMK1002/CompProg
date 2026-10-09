#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int n;
int arr[200005];
map<long long, long long> cnt;

void solve() {
	cin >> n;
	long long ans = 0;
	set<int> st;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(arr[i], mx);
		ans += cnt[arr[i]] * (cnt[arr[i]] - 1) * 3;
		st.insert(arr[i]);
		cnt[arr[i]]++;
	}
	for (long long i : st) {
		if (i > 1e6) {
			for (int j = 2; i * j <= mx; j++) {
				if (i % j != 0) continue;
				if (cnt.find(i / j) == cnt.end() || cnt.find(i * j) == cnt.end()) continue;
				ans += cnt[i] * cnt[i / j] * cnt[i * j];
			}
		}
		else {
			if (i != 1 && !(cnt.find(1) == cnt.end() || cnt.find(i * i) == cnt.end())) ans += cnt[1] * cnt[i] * cnt[i * i];
			for (int j = 2; j * j <= i; j++) {
				if (i % j != 0) continue;
				if (!(cnt.find(i / j) == cnt.end() || cnt.find(i * j) == cnt.end())) {
					ans += cnt[i] * cnt[i / j] * cnt[i * j];
				}
				if (j * j != i && !(cnt.find(j) == cnt.end() || cnt.find(i * i / j) == cnt.end())) {
					ans += cnt[i] * cnt[j] * cnt[i * i / j];
				}
			}
		}
	}
	cout << ans << endl;
	cnt.clear();
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