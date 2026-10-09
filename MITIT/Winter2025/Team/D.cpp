#include <bits/stdc++.h>
using namespace std;

struct pt {
    long long x, y;
	pt () {
		x = 0; y = 0;
	}
	pt (long long a, long long b) {
		x = a; y = b;
	}
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

const pt ori(0, 0);

long long orientation(pt a, pt b, pt c) {
    long long v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt b, pt c) {
	bool include_collinear = true;
    long long o = orientation(ori, b, c);
    return !(o < 0 || (include_collinear && o == 0));
}

long long dist(pt a, pt b) {
	long long dx = a.x - b.x;
	long long dy = a.y - b.y;
	return dx * dx + dy * dy;
}

long long n;
pt pts[505];
vector<long long> adj[505];
bool fastAdj[505][505];
long long cnt[505];
long long temp[505];
const long long mod = 998244353;

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		// x = rand();
		// y = rand();
		pts[i].x = x;
		pts[i].y = y;
	}
	// cout << cw(pts[0], pts[1]) << endl;
	sort(pts, pts + n, cw);
	// reverse(pts, pts + n);
	// now pts should be cw if I did stuff right
	// for (long long i = 0; i < n; i++) cout << pts[i].x << " " << pts[i].y << endl;
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			if (dist(pts[i], pts[j]) <= max(dist(ori, pts[j]), dist(ori, pts[i]))) continue;
			if (cw(pts[i], pts[j])) {
				adj[i].push_back(j);
				fastAdj[i][j] = true;
			}
			else {
				adj[j].push_back(i);
				fastAdj[j][i] = true;
			}
		}
	}

	vector<long long> cyclic(6, 0);
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) cnt[i] = 0;
		for (long long j = 0; j < n; j++) temp[i] = 0;
		cnt[i] = 1;

		for (long long _ = 0; _ < 6; _++) {
			for (long long j = 0; j < n; j++) {
				if (j == i && _ != 0) continue;
				for (long long k : adj[j]) { // from j to k
					if ((j < k ^ ((j > i) == (k > i))) && j != i && k != i) continue; // DOUBLE CHECK THIS
					temp[k] += cnt[j];
					temp[k] %= mod;
				}
			}
			for (long long j = 0; j < n; j++) {
				if (j == i) cyclic[_] += cnt[j];
				if (fastAdj[i][j]) ans += cnt[j];
				cyclic[_] %= mod;
				ans %= mod;
			}

			for (long long j = 0; j < n; j++) cnt[j] = temp[j];
			for (long long j = 0; j < n; j++) temp[j] = 0;
		}
	}
	ans += cyclic[0];
	ans %= mod;
	vector<long long> inv = {-1, 1, 499122177, 332748118, 748683265, 598946612};
	for (long long i = 1; i < 6; i++) {
		ans += cyclic[i] * inv[i] % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
// 3
// 1 0
// 0 1
// -1 0

// 2
// 0 1
// 0 -1