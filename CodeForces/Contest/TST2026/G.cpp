#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[200005];
int forw[200005];
int backw[200005];

void solve() {
	cin >> n;
	arr[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		forw[i] = (arr[i] < arr[i - 1]) ? forw[i - 1] + 1 : 1;
	}
	arr[n + 1] = -1;
	for (int i = n; i >= 1; i--) {
		backw[i] = (arr[i] < arr[i + 1]) ? backw[i + 1] + 1 : 1;
	}

	int l = 1;
	int r = n;
	int mn = -1;
	while (l <= r) {
		if (min(arr[l], arr[r]) <= mn) {
			if (arr[l] < arr[r]) r -= forw[r];
			else l += backw[l];
			break;
		}
		else if (arr[l] == arr[r]) {
			if (backw[l] % 2 == 0 && forw[r] % 2 == 0) r -= forw[r];
			else l++;
			break;
		}

		if (arr[l] < arr[r]) {
			if (forw[r] % 2) {
				r -= forw[r];
				break;
			}
			mn = arr[l];
			l++;
		}
		else if (arr[l] > arr[r]) {
			if (backw[l] % 2) {
				l += backw[l];
				break;
			}
			mn = arr[r];
			r--;
		}
	}
	int turns = n - r + l - 1;
	cout << ((turns % 2) ? "Alice" : "Bob") << endl;
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = 0;
		forw[i] = 0;
		backw[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
