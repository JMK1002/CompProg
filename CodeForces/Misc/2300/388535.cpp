#include <iostream>
using namespace std;

const int b = 18;

int l, r;
int t[(1<<20)+2];
int arr[200005];
int cnt[b+1];
int act[b+1];
 
int getMx(int v) {
	int run = 1 << b;
	int x = 1;
	int run2 = 0;
	for (int j = b; j >= 0; j--, run >>= 1) {
		run2 <<= 1;
		if (t[x * 2] && t[x * 2 + 1]) {
			x *= 2;
			x += ((run & v) == 0);
			run2 += ((run & v) == 0);
		}
		else if (t[x * 2]) {
			x *= 2;
		}
		else {
			x *= 2;
			x += 1;
			run2++;
		}
	}
	return run2 ^ v;
}
 
int getMn(int v) {
	int run = 1 << b;
	int x = 1;
	int run2 = 0;
	for (int j = b; j >= 0; j--, run >>= 1) {
		run2 <<= 1;
		if (t[x * 2] && t[x * 2 + 1]) {
			x *= 2;
			x += ((run & v) != 0);
			run2 += ((run & v) != 0);
		}
		else if (t[x * 2]) {
			x *= 2;
		}
		else {
			x *= 2;
			x += 1;
			run2++;
		}
	}
	return run2 ^ v;
}

int get() {
	int ans = 0;
	for (int i = 0, run = 1; i <= b; i++, run <<= 1) {
		if (cnt[i] != act[i]) {
			ans += run;
		}
	}
	return ans;
}

void solve() {
	cin >> l >> r;
	int n = r - l + 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// arr[i] = i;
		int run = 1 << b;
		int x = 1;
		for (int j = b; j >= 0; j--, run >>= 1) {
			x <<= 1;
			x += ((run & arr[i]) != 0);
			t[x]++;
		}
	}
	// cout << getMn(18) << " " << getMx(18) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0, run = 1; j <= b; j++, run <<= 1) {
			cnt[j] += (run & arr[i]) != 0;
			act[j] += (run & (i + l)) != 0;
		}
	}

	int ans = 0;
	if (n % 2 == 1) ans = get();
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0, run = 1; j <= b; j++, run <<= 1) {
				cnt[j] -= (run & arr[i]) != 0;
				act[j] -= (run & (l)) != 0;
			}
			for (int j = b, run = 1 << b, x = 1; j >= 0; j--, run >>= 1) {
				x <<= 1;
				x += ((run & arr[i]) != 0);
				t[x]--;
			}

			int val = get();
			if ((val ^ arr[i]) == l && getMn(val) == l + 1 && getMx(val) == r) {
				ans = val;
				break;
			}

			for (int j = 0, run = 1; j <= b; j++, run <<= 1) {
				cnt[j] += (run & arr[i]) != 0;
				act[j] += (run & (l)) != 0;
			}
			for (int j = b, run = 1 << b, x = 1; j >= 0; j--, run >>= 1) {
				x <<= 1;
				x += ((run & arr[i]) != 0);
				t[x]++;
			}
		}
	}

	cout << ans << endl;

	for (int i = 0; i < n; i++) {
		// cin >> arr[i];
		int run = 1 << b;
		int x = 1;
		for (int j = b; j >= 0; j--, run >>= 1) {
			x <<= 1;
			x += ((run & arr[i]) != 0);
			t[x] = 0;
		}
	}
	for (int i = 0; i <= n; i++) arr[i] = 0;
	for (int i = 0; i <= b; i++) {
		act[i] = 0;
		cnt[i] = 0;
	}
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