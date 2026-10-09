#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> arr;
vector<vector<bool>> temp;
vector<vector<vector<pair<bool, int>>>> ev; // ev[m][n] is set of events (bool is to add or remove for true or false)
vector<vector<vector<pair<bool, int>>>> e2v; // ev[m][n] is set of events (bool is to add or remove for true or false)
vector<vector<int>> ans;
vector<vector<int>> temp2;

void solve() {
	cin >> n >> m;
	bool swapped = false;
	arr.assign(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (s[j] - '0');
			// arr[i].push_back(1);
		}
	}
	if (n > m) { // ! n < m
		swapped = true;
		temp.assign(m, vector<bool>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = arr[j][i];
			}
		}
		swap(n, m);
		arr.clear();
		arr = temp;
		temp.clear();
	}
	ans.assign(n, vector<int>(m));
	ev.assign(m, {});
	for (int i = 0; i < m; i++) {
		ev[i].assign(n + 1, {});
	}
	// cout << "SDF" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<int> inds;
			for (int k = 0; k < m; k++) {
				if (arr[i][k] && arr[j][k]) inds.push_back(k);
			}
			int ind = -1;
			for (int k = 0; k < m; k++) {
				if (ind != -1 && ind != inds.size() - 1) {
					int area = (inds[ind + 1] - inds[ind] + 1) * (j - i + 1);
					ev[k][i].push_back({true, area});
					ev[k][j + 1].push_back({false, area});
				}
				if (ind != inds.size() - 1 && inds[ind + 1] == k) {
					ind++;
					if (ind != -1 && ind != inds.size() - 1) {
						int area = (inds[ind + 1] - inds[ind] + 1) * (j - i + 1);
						ev[k][i].push_back({true, area});
						ev[k][j + 1].push_back({false, area});
					}
				}
			}
		}
	}
	// cout << "SDF" << endl;
	for (int k = 0; k < m; k++) {
		multiset<int> ms;
		for (int i = 0; i < n; i++) {
			for (pair<bool, int> p : ev[k][i]) {
				if (p.first) ms.insert(p.second);
				else ms.erase(ms.find(p.second));
			}
			if (ms.empty()) ans[i][k] = 0;
			else ans[i][k] = *ms.begin();
		}
	}
	// cout << "SDF" << endl;
	if (swapped) {
		for (int i = 0; i < m; i++) {
			temp2.push_back({});
			for (int j = 0; j < n; j++) {
				temp2[i].push_back(ans[j][i]);
			}
		}
		swap(n, m);
		ans.clear();
		ans = temp2;
		temp.clear();
	}

	for (vector<int> b : ans) {
		for (int j : b) cout << j << " ";
		cout << endl;
	}
	// cout << "DONE" << endl;

	arr.clear();
	temp.clear();
	temp2.clear();
	ans.clear();
	ev.clear();
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

// 011101
// 010001
// 100010
// 101110

// 0011
// 1100
// 1001
// 1001
// 0011
// 1100