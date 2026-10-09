#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	long long cnt = 0;
	long long s = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		cnt += (arr[i] > 0);
		s += arr[i];
	}
	cout << min(cnt, s - n + 1) << endl;


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