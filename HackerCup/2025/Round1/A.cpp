#include <bits/stdc++.h>
using namespace std;

int n;
int arr[500005];
int perm[500005];
bool reached[500005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		perm[i] = i;
	}
	// for (int i = 0; i < n; i++) cout << arr[perm[i]] << endl;

	int low = 0;
	int high = 1e9 + 2;
	while (high - low > 1) {
		int mid = (high + low) / 2;

		for (int i = 0; i < n; i++) reached[i] = false;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid) reached[i] = true;
			if (i > 0 && reached[i - 1] && abs(arr[i - 1] - arr[i]) <= mid) reached[i] = true;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1 && reached[i + 1] && abs(arr[i + 1] - arr[i]) <= mid) reached[i] = true;
		}

		bool works = true;
		for (int i = 0; i < n; i++) works &= reached[i];
		if (works) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	cout << high << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		reached[i] = 0;
		perm[i] = 0;
	}
}

int main() {
	// ulimit -s unlimited
	freopen("snake_scales_chapter_2_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		cout << "Case #" << cnt << ": ";
		solve();
		cnt++;
	}
	return 0;
}