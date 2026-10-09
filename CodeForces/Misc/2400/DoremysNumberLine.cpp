#include <bits/stdc++.h>
using namespace std;

#define int long long

struct pt {
	int a, b, ind;
	pt() : a(0), b(0), ind(0) {}
};

int n, k;
pt arr[100005];
int mxCol[100005];

int fnd(int ind) {
	int mx = arr[ind].a;
	if (ind == 1) mx = max(mx,  arr[ind].b + fnd(ind - 1));
	else if (ind >= 2) mx = max(mx, arr[ind].b + max(mxCol[ind - 2], fnd(ind - 1)));
	return min(arr[ind].a + arr[ind].b, mx);
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].b;
		arr[i].ind = i;
	}
	int mx = arr[0].a;
	int b1 = arr[0].b;
	sort(arr, arr + n, [&](pt p1, pt p2) {
		return p1.a < p2.a;
	});

	mxCol[0] = arr[0].a + arr[0].b;
	for (int i = 1; i < n; i++) mxCol[i] = max(mxCol[i - 1], arr[i].a + arr[i].b);

	if (arr[n - 1].ind != 0) mx += b1;
	else {
		mx = fnd(n - 1);
	}

	if (mx >= k) cout << "YES" << endl;
	else cout << "NO" << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = pt();
		mxCol[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
