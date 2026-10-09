#include <bits/stdc++.h>
using namespace std;

long long n;
long long s;
pair<long long, long long> rng;

long long q(long long l, long long r) {
	cout << "? " << l << " " << r << endl;
	cout.flush();
	long long res; // ! MAKE EVERYTHING LONG LONG PLZZZZ
	cin >> res;
	return res;
}

void getNxt() {
	long long low = rng.first;
	long long high = rng.second;
	long long tar = s / 2;
	while (high - low > 1) {
		long long mid = (low + high) / 2;
		long long x = q(rng.first, mid);
		if (x == tar) {
			low = mid;
			break;
		}
		else if (x < tar) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	if (low - rng.first + 1 < rng.second - low) {
		rng = {rng.first, low};
	}
	else {
		rng = {low + 1, rng.second};
	}
	s = s / 2;
}

void solve() {
	cin >> n;
	rng = {1, n};
	s = q(1, n);
	while (rng.first != rng.second) {
		getNxt();
	}
	cout << "! " << s << endl;
	cout.flush();
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