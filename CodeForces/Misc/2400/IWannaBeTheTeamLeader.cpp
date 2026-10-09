#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n, m;
int arr[200005];
int perm[200005];
int nxt[200005][25];
int dp[2000000];
int best[2000000];
vector<int> ans[25];
int b[25];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	iota(perm, perm + n, 0);
	sort(perm, perm + n, [&] (int a, int b) {
		return arr[a] < arr[b];
	});
	reverse(perm, perm + n);
	sort(arr, arr + n);
	reverse(arr, arr + n);
	for (int j = 0; j < m; j++) {
		int val = b[j];
		int r = 0;
		for (int l = 0; l < n; l++) {
			while (r < n && arr[r] * (r - l + 1) < val) r++;
			nxt[l][j] = r + 1;
		}
		nxt[n + 1][j] = 10000000;
		nxt[n][j] = 10000000;
	}

	for (int i = 1; i < (1 << m); i++) {
		vector<pair<int, int>> vals;
		dp[i] = 10000000;
		for (int j = 0, run = 1; j < m; j++, run <<= 1) {
			if (i & run) vals.push_back({run, j});
		} 
		for (pair<int, int> v : vals) {
			int a = v.first;
			int b = v.second;
			if (dp[a ^ i] != 10000000 && nxt[dp[a ^ i]][b] < dp[i]) {
				dp[i] = nxt[dp[a ^ i]][b];
				best[i] = b;
			}
		}
	}

	if (dp[(1 << m) - 1] > n) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vector<int> ord;
	int a = (1 << m) - 1;
	for (int i = 0; i < m; i++) {
		ord.push_back(best[a]);
		// cout << best[a] << " " << dp[a ^ (1 << best[a])] << endl;
		a = a ^ (1 << best[a]);
	}
	// cout << endl;
	reverse(ord.begin(), ord.end());
	int amnt = 0;
	for (int i : ord) {
		int namnt = nxt[amnt][i];
		for (int j = amnt; j < namnt; j++) ans[i].push_back(j);
		amnt = namnt;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i].size() << " ";
		for (int j : ans[i]) cout << perm[j] + 1 << " ";
		cout << endl;
	}
	return 0;
}