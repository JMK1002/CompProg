#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

long long n, k;
long long arr[200005];
long long narr[200005];
long long pre[200005];

long long rem(long long amnt) {
	long long last[2] = {-1, -1};
	for (long long i = 1; i <= n; i++) narr[i] = arr[i];
	for (long long j = 0; j < 2; j++) {
		long long tamnt = amnt;
		for (long long i = 1; i < n; i++) {
			pre[i] = narr[i + 1] - narr[i];
		}
		long long asdf = 1;
		for (long long i = n - 1; i >= 1; i--) {
			if (amnt >= asdf * pre[i]) {
				amnt -= asdf * pre[i];
				pre[i] = 0;
			}
			else {
				pre[i] -= amnt / asdf;
				amnt %= asdf;
				break;
			}
			asdf++;
		}
		for (long long i = 2; i <= n; i++) {
			narr[i] = narr[i - 1] + pre[i - 1];
		}
		last[j] = narr[n] + 1;
		for (long long i = n; i > n - amnt; i--) {
			last[j] = narr[i];
			narr[i]--;
		}
		sort(narr + 1, narr + (1 + n));

		amnt = tamnt;
		reverse(narr + 1, narr + (1 + n));
		for (long long i = 1; i <= n; i++) narr[i] *= -1;
	}
	if (last[0] == -1) return 0;
	last[1] *= -1;
	return last[1] + 1 - last[0] + k;
}

// m swaps are made
bool test(long long m) {
	if (rem(m) <= 0) return true;
	return false;
}

void solve() {
	cin >> n >> k;
	long long s = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	sort(arr + 1, arr + (n + 1));


	long long low = 0;
	long long high = 0;
	for (long long i = 1; i <= n; i++) {
		high += abs(s / n + ((n - i) < (s % n)) - arr[i]);
	}
	high /= 2;
	if (rem(high) > 0) {
		while (high - low > 1) {
			long long mid = (high + low) / 2;
			if (test(mid)) low = mid;
			else high = mid;
		}
	}
	else low = high;
	rem(low);
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		ans += narr[i] * (narr[i] + 1) / 2;
	}
	ans += k * low;
	cout << ans << endl;
	for (long long i = 1; i <= n; i++) {
		arr[i] = 0;
		narr[i] = 0;
		pre[i] = 0;
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
	return 0;
}