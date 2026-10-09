#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;
pair<pair<int, int>, int> arr[200005];
int ans[200005];

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> arr[i].first.second >> arr[i].first.first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + k + 1);
	map<int, int> mp;
	int mx = 0;
	for (int i = 1; i <= k; i++) {
		if (arr[i].first.second > mx) {
			mx = arr[i].first.second;
			mp[arr[i].first.first] = i;
		}
	}
	vector<pair<int, int>> hull;
	hull.push_back({1, 0});
	for (pair<int, int> p : mp) {
		hull.push_back(p);
	}
	hull.push_back({m + 1, n});
	int suff = 0;
	for (int i = hull.size() - 2; i >= 1; i--) {
		suff += (hull[i + 1].first - hull[i].first) * (n - arr[hull[i].second].first.second);
	}
	int pre = 0;
	int ind = 1;
	int tot = 0;
	for (int i = 1; i < hull.size() - 1; i++) {
		pre += (hull[i].first - hull[i - 1].first) * (n - arr[hull[i - 1].second].first.second);
		tot = pre + suff;
		suff -= (hull[i + 1].first - hull[i].first) * (n - arr[hull[i].second].first.second);
		int h = arr[hull[i - 1].second].first.second;
		map<int, int> temp;
		while (ind <= k && arr[ind].first.first < hull[i + 1].first) {
			if (ind == hull[i].second) {
				ind++;
				continue;
			}
			if (arr[ind].first.second > h) {
				h = arr[ind].first.second;
				temp[arr[ind].first.first] = h;
			}
			ind++;
		}
		vector<pair<int, int>> tempHull;
		tempHull.push_back({hull[i].first, arr[hull[i - 1].second].first.second});
		for (pair<int, int> p : temp) tempHull.push_back(p);
		tempHull.push_back({hull[i + 1].first, (i + 1 == hull.size() - 1) ? n : arr[hull[i + 1].second].first.second});
		for (int j = 1; j < tempHull.size(); j++) {
			ans[arr[hull[i].second].second] += (tempHull[j].first - tempHull[j - 1].first) * (n - tempHull[j - 1].second);
		}
		ans[arr[hull[i].second].second] += pre + suff;
		ans[arr[hull[i].second].second] -= tot;
	}
	cout << tot << endl;
	for (int i = 1; i <= k; i++) cout << ans[i] << " ";
	cout << endl;
	for (int i = 0; i <= k; i++) {
		arr[i] = {{0, 0}, 0};
		ans[i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}


// 3 5 6
// 3 5
// 1 1
// 3 4
// 2 1
// 1 3
// 1 5
