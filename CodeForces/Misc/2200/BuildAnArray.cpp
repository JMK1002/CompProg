#include <iostream>
using namespace std;

long long n, k;
long long arr[100005];
long long cnt[100005];
pair<long long, long long> amnt[100005]; // first is add to left side, second is right

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		while (arr[i] % 2 == 0) {
			arr[i] /= 2;
			cnt[i]++;
		}
	}

	amnt[0].second = (1 << cnt[0]);
	for (long long i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1] || (arr[i] == arr[i - 1] && cnt[i] < cnt[i - 1])) amnt[i].second = (1 << cnt[i]);
		else {
			amnt[i].second = (1 << cnt[i]) - (1 << (cnt[i - 1] + 1)) + 1;
		}
	}

	amnt[n - 1].first = (1 << cnt[n - 1]);
	for (long long i = n - 2; i >= 0; i--) {
		if (arr[i] != arr[i + 1] || (arr[i] == arr[i + 1] && cnt[i] < cnt[i + 1])) amnt[i].first = (1 << cnt[i]);
		else {
			amnt[i].first = (1 << cnt[i]) - (1 << (cnt[i + 1] + 1)) + 1;
		}
	}

	long long ans = 0;
	for (long long i = 0; i < n; i++) ans += amnt[i].second;

	long long act = ans;

	for (long long i = 1; i < n; i++) {
		ans -= (1 << cnt[i - 1]) + amnt[i].second;
		ans += amnt[i - 1].first + (1 << cnt[i]);
		act = max(act, ans);
	}
	// cout << act << " " << k << endl;
	cout << (k <= act ? "YES" : "NO") << endl;
	for (long long i = 0; i <= n; i++) {
		arr[i] = 0;
		cnt[i] = 0;
		amnt[i].first = 0;
		amnt[i].second = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}