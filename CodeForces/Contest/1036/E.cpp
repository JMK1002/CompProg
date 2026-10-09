#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

long long n;
long long arr[100000];
vector<long long> temp;
long long pre[100000];
vector<vector<long long>> ans;

long long getSol(long long l, long long r, long long rem, long long d) {
	if (d >= 18) {
		cout << -1 << endl;
		return -1;
	}
	long long ind = -1;
	long long diff = 1e18;
	for (long long i = l; i < r; i++) {
		long long lSum = pre[i] - pre[l - 1];
		long long rSum = pre[r] - pre[i];
		if (abs(lSum - rSum) < diff) {
			ind = i;
			diff = abs(lSum - rSum);
		}
	}
	long long lSum = pre[ind] - pre[l - 1];
	long long rSum = pre[r] - pre[ind];
	long long amntRemoved = 0;
	// if diff >= lsum + rsum?
	long long res = -1;
	if (diff <= rem) {
		amntRemoved = (lSum + rSum - rem) / 2;
		res = d;
	}
	else if (rSum < lSum) {
		amntRemoved = rSum;
		res = getSol(l, ind, rem + rSum, d + 1);
	}
	else {
		amntRemoved = lSum;
		res = getSol(ind + 1, r, rem + lSum, d + 1);
	}



	temp = vector<long long>(n + 2);
	long long run = 0;
	for (long long i = l; i <= ind; i++) {
		temp[i] = min(arr[i], amntRemoved - run);
		run += temp[i];
	}
	run = 0;
	for (long long i = ind + 1; i <= r; i++) {
		temp[i] = min(arr[i], amntRemoved - run);
		run += temp[i];
	}
	ans.push_back(temp);
	for (long long i = 1; i <= n; i++) arr[i] -= temp[i];

	return res;
}

void solve() {
	cin >> n;
	long long mx = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		pre[i] = pre[i - 1] + arr[i];
	}
	if (pre[n] % 2 == 1 || mx > pre[n] - mx) {
		cout << -1 << endl;
		return;
	}
	cout << getSol(1, n, 0, 1) << endl;
	reverse(ans.begin(), ans.end());
	for (long long i = 0; i < ans.size(); i++) {
		for (long long j = 1; j <= n; j++) cout << ans[i][j] << " ";
		cout << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;

	// TODO MAKE EVERYTHING LONG LONG
	while (t--) {
		solve();
		for (long long i = 0; i <= n + 2; i++) {
			arr[i] = 0;
			pre[i] = 0;

		}
		temp.clear();
		ans.clear();
	}
	return 0;
}