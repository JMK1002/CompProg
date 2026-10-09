#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[200005];
int cnt[200005];
int cntCnts[200005];
int mex = 0;


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int irrelevant = 0;
	int extra = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mex) irrelevant++;
		else if (arr[i] < mex) {
			extra++;
			cnt[arr[i]]++;
		}
		if (mex == arr[i]) {
			mex++;
			cnt[arr[i]]++;
		}
	}
	for (int i = 0; i <= n; i++) {
		cntCnts[cnt[i]]++;
	}
	int ans = 1;
	for (int i = 1; i <= extra + irrelevant; i++) {
		cout << ans << " ";
		ans += cntCnts[i];
	}
	cout << ans << " ";
	for (int i = mex; i >= 1; i--) cout << i << " ";
	cout << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		cntCnts[i] = 0;
		cnt[i] = 0;
	}
	mex = 0;
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