#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[200005];
int m[200005];
vector<pair<int, int>> ev[2000005]; 
pair<int, int> ps[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		cin >> m[i];
	}
	set<int> st;
	for (int i = 0; i < n; i++) {
		int tot = arr[i].first + arr[i].second - m[i];
		st.insert(tot);
		ev[tot].push_back({max(0, arr[i].first - m[i]), -1 * (i + 1)});
		ev[tot].push_back({min(tot, arr[i].first), (i + 1)});
	}
	set<int> curr;
	int ans = 0;
	for (int i : st) {
		sort(ev[i].begin(), ev[i].end());
		for (pair<int, int> p : ev[i]) {
			if (p.second > 0 && curr.find(p.second) != curr.end()) {
				while (!curr.empty()) {
					int a = *curr.begin();
					curr.erase(curr.begin());
					ps[a - 1] = {p.first, i - p.first};
				}
				ans++;
			} 
			else if (p.second < 0) {
				curr.insert(abs(p.second));
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << arr[i].first - ps[i].first << " " << arr[i].second - ps[i].second << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = {0, 0};
		m[i] = 0;
		ps[i] = {0, 0};
	}
	for (int i : st) ev[i].clear();
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