#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];
map<long long, long long> cnt;
set<pair<long long, long long>> odd;

void solve() {
	cin >> n;
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		sum += arr[i];
	}
	for (long long i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) continue;
		odd.insert({cnt[arr[i]], arr[i]});
	}
	long long ans[2] = {0, 0};
	int asdf = 0;
	while (!odd.empty()) {
		auto ptr = --odd.end();
		ans[asdf % 2] += ptr->first;
		sum -= ptr-> first;
		odd.erase(ptr);
		asdf++;
	}
	cout << ans[0] + sum / 2 << " " << ans[1] + sum / 2 << endl;

	odd.clear();
	cnt.clear();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}