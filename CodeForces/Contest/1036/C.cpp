#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int n;
int arr[1000000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	long long x = 1;
	for (int i = 0; i < n - 1; i++) {
		x = lcm(x, arr[i] / __gcd(arr[i], arr[i + 1]));
	}
	cout << x << endl;
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