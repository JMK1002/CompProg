#include <iostream>
#include <algorithm>
using namespace std;

long long n, q;
long long arr[2002][2002];
long long pre[2002][2002]; // normal prefix sum
long long inc[2][2002][2002]; // prefix sum with incrementation horizontally (0) and vertically (1)

#define getSum(a) (a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1])

void solve() {
	cin >> n >> q;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			pre[i][j] = arr[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			inc[0][i][j] = arr[i][j] * (j) + inc[0][i - 1][j] + inc[0][i][j - 1] - inc[0][i - 1][j - 1];
			inc[1][i][j] = arr[i][j] * (i - 1) + inc[1][i - 1][j] + inc[1][i][j - 1] - inc[1][i - 1][j - 1];
		}
	}
	while (q--) {
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << (getSum(inc[0]) - (y1 - 1) * getSum(pre) + (y2 - y1 + 1) * (getSum(inc[1]) - (x1 - 1) * getSum(pre))) << " ";
	} 
	cout << endl;
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