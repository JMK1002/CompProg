#include <bits/stdc++.h>
using namespace std;

// when iterating over the entire range and you find the end of a segment, you do 
// dp[i] + mx[i] where mx[i] is the mx segments inside of segment i
// computing mx[i] you find all segments j which are inside i then dp

int n;

int mx[3005];
pair<int, int> arr[3005];

void getMx(int v) {
	vector<int> inds;
	for (int i = 0; i < n; i++) {
		if (i == v) continue;
		if (arr[i].first >= arr[v].first && arr[i].second <= arr[v].second) inds.push_back(i);
	}
	for (int i : inds) {
		if (mx[i] == -1) getMx(i);
	}
	set<pair<int, pair<bool, int>>> ev; // false is start
	map<int, int> mp;
	int ans = 0;
	for (int i : inds) {
		ev.insert({arr[i].first, {false, i}});
		ev.insert({arr[i].second, {true, i}});
	}
	for (auto p : ev) {
		int i = p.second.second;
		if (p.second.first == false) {
			mp[arr[i].second] = max(mp[arr[i].second], ans + mx[i]);
		}
		else {
			ans = max(ans, mp[arr[i].second]);
		}
	}
	mx[v] = ans + 1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		mx[i] = -1;
		cin >> arr[i].first >> arr[i].second;
	}
	arr[n] = {1, 2e5 + 2};
	getMx(n);
	cout << mx[n] - 1 << endl;
	for (int i = 0; i <= n; i++) {
		mx[i] = 0;
		arr[i] = {0, 0};
	}
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