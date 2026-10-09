#include <iostream>
using namespace std;

long long n;
string s;
long long arr[400025];
long long zeroPtr = 200011;

void solve() {
	cin >> n >> s;
	zeroPtr = 200011;
	long long greater = 0;
	long long less = 0;
	long long run = 0;
	long long ans = 0;
	for (char c : s) {
		arr[zeroPtr]++;
		if (c == '0') {
			less += arr[zeroPtr];
			zeroPtr++;
			greater -= arr[zeroPtr];
			run += less;
		}
		else {
			greater += arr[zeroPtr];
			zeroPtr--;
			less -= arr[zeroPtr];
			run += greater;
		}
		ans += run;
	}
	cout << ans << endl;
	for (long long i = 200011 - n - 10; i <= 200011 + n + 10; i++) {
		arr[i] = 0;
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