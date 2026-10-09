#include <iostream>
#include <map>
#include <set>
using namespace std;

long long n, q;
long long arr[100005];
map<long long, set<long long>> inv;
set<long long> d;

void getDiv(long long k) {
	d.clear();
	for (long long i = 1; i * i <= k; i++) {
		if (k % i != 0) continue;
		d.insert(i);
		d.insert(k / i);
	}
	d.erase(1);
}

long long getNext(long long pos, long long k) {
	long long res = n;
	for (long long divisor : d) {
		auto ptr = inv[divisor].lower_bound(pos);
		if (ptr == inv[divisor].end()) continue;
		res = min(res, *ptr);
	}
	return res;
}

void solve() {
	cin >> n >> q;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		inv[arr[i]].insert(i);
	}

	while (q--) {
		long long ans = 0;
		long long k, l, r;
		cin >> k >> l >> r;
		l--; r--;
		long long pos = l;
		while (pos <= r) {
			while (k % arr[pos] == 0) k /= arr[pos];
			getDiv(k);
			long long newPos = getNext(pos, k);
			newPos = min(newPos, r + 1);
			ans += k * (newPos - pos);

			pos = newPos;
		}
		cout << ans << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
		inv.clear();
	}
	return 0;
}