#include <iostream>
using namespace std;

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	long long totMx = 0;
	long long sum = 0;
	long long oddCnt = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i] % 2 == 1) {
			oddCnt++;
		}
		totMx = max(totMx, arr[i]);
		sum += arr[i];
	}
	if (oddCnt == 0 || oddCnt == n) {
		cout << totMx << endl;
	}
	else {
		cout << sum - (oddCnt - 1) << endl;
	}
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}