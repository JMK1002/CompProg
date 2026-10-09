#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[2][200005];

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) cin >> a[0][i];
	for (long long i = 0; i < m; i++) cin >> a[1][i];
	sort(a[0], a[0] + n);
	sort(a[1], a[1] + m);
	long long km = min(min(n, m), (n + m) / 3);
	// if (m > n) { // ! m <= n
	// 	swap(m, n);
	// 	swap(a[0], a[1]);
	// }

	vector<long long> p[2];
	long long psz[2];
	for (long long i = 0; i < min(n / 2, m); i++) p[0].push_back(-1 * a[0][i] + a[0][n - i - 1]);
	for (long long i = 0; i < min(m / 2, n); i++) p[1].push_back(-1 * a[1][i] + a[1][m - i - 1]);
	psz[0] = p[0].size();
	psz[1] = p[1].size();
	
	// long long cnt = n % 2;
	// long long cnt2 = psz[0];
	// while (psz[1] >= cnt + 2) {
	// 	long long v = p[1][cnt] + p[1][cnt + 1] - p[0][cnt2 - 1];
	// 	cnt += 2;
	// 	cnt2--;
	// 	p[0].push_back(v);
	// }

	// cnt = m % 2;
	// cnt2 = psz[1];
	// while (psz[0] >= cnt + 2) {
	// 	long long v = p[0][cnt] + p[0][cnt + 1] - p[1][cnt2 - 1];
	// 	cnt += 2;
	// 	cnt2--;
	// 	p[1].push_back(v);
	// }

	p[0].push_back(-1e17);
	p[1].push_back(-1e17);

	long long ptr[2] = {0, 0};
	long long s = 0;
	cout << km << endl;
	for (long long i = 0; i < km; i++) {
		if (i >= n / 2 + n % 2 && ptr[0] == psz[0]) {
			ptr[0]--;
			s -= p[0][ptr[0]];
			s += p[1][ptr[1]];
			s += p[1][ptr[1] + 1];
			p[0].pop_back();
			ptr[1] += 2;
		}
		else if (i >= m / 2 + m % 2 && ptr[1] == psz[1]) {
			ptr[1]--;
			s -= p[1][ptr[1]];
			s += p[0][ptr[0]];
			s += p[0][ptr[0] + 1];
			p[1].pop_back();
			ptr[0] += 2;
		}
		else if (m - ptr[1] * 2 - ptr[0] < 2 || n - ptr[0] * 2 - ptr[1] >= 2 && p[0][ptr[0]] > p[1][ptr[1]]) {
			s += p[0][ptr[0]];
			ptr[0]++;
		}
		else {
			s += p[1][ptr[1]];
			ptr[1]++;
		}
		cout << s << " ";
	}
	cout << endl;
	for (long long i = 0; i <= max(n, m); i++) {
		a[0][i] = 0;
		a[1][i] = 0;
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