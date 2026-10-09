#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long n;
long long arr[300005];
long long temp[300005];
long long p[300005];
long long calc[300005];

void solve() {
	cin >> n;
	long long s = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		s += arr[i];
	}

	for (long long j = 0; j < 2; j++) {
		for (long long i = 1; i <= n; i++) {
			temp[i] = arr[i] - i;
		}
		stack<long long> st;
		for (long long i = 1; i <= n; i++) p[i] = 0;
		for (long long i = n; i >= 1; i--) {
			while (!st.empty() && temp[st.top()] > temp[i]) {
				p[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		for (long long i = 1; i <= n; i++) {
			if (i - p[i] >= arr[i]) temp[i] = arr[i] * (arr[i] + 1) / 2;
			else temp[i] = arr[i] * (arr[i] + 1) / 2 - (arr[i] - (i - p[i])) * (arr[i] - (i - p[i]) + 1) / 2 + temp[p[i]];
			calc[i] += temp[i];
		}
		reverse(arr + 1, arr + (n + 1));
		reverse(calc + 1, calc + (n + 1));
	}
	for (long long i = 1; i <= n; i++) calc[i] -= arr[i];
	long long ans = s;
	for (long long i = 1; i <= n; i++) {
		ans = min(ans, s - calc[i] + arr[i]);
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		temp[i] = 0;
		p[i] = 0;
		calc[i] = 0;
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