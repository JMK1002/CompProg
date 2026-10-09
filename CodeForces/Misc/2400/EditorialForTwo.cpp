#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int arr[300005];
int tot[300005];
priority_queue<int> st;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	long long low = 0;
	long long high = 1e15;
	while (high - low > 1) {
		for (int i = 0; i <= n; i++) tot[i] = 0;

		long long mid = (high + low) / 2;
		for (int j = 0; j < 2; j++) {
			long long sum = 0;
			for (int i = 1; i <= n; i++) {
				st.push(arr[i]);
				sum += arr[i];
				while (sum > mid) {
					sum -= st.top();
					st.pop();
				}
				tot[i] += st.size();
			}
			reverse(tot, tot + (n + 1));
			reverse(arr + 1, arr + (n + 1));
			while (!st.empty()) st.pop();
		}
		int mx = 0;
		for (int i = 0; i <= n; i++) mx = max(tot[i], mx);

		if (mx >= k) high = mid;
		else low = mid;
	}
	cout << high << endl;
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