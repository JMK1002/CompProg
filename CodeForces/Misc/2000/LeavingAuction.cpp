#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n;
int arr[200005];
vector<int> inds[200005];
vector<pair<int, int>> lastInds; // {ind, person}

int cntBids(int p, int l) {
	return inds[p].end() - lower_bound(inds[p].begin(), inds[p].end(), l);
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u >> arr[i];
		u--;
		inds[u].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (inds[i].empty()) continue;
		lastInds.push_back({*--inds[i].end(), i});
	}
	sort(lastInds.begin(), lastInds.end());

	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		set<int> people;
		for (int i = 0; i < k; i++) {
			int u;
			cin >> u;
			u--;
			people.insert(u);
		}
		int winner = -1;
		for (int i = lastInds.size() - 1; i >= 0; i--) {
			int p = lastInds[i].second;
			if (lastInds[i].first == -1) break;
			if (people.find(p) != people.end()) continue;
			winner = p;
			break;
		}
		if (winner == -1) {
			cout << 0 << " " << 0 << endl;
			continue;
		}

		int l = -1;
		int h = inds[winner].size() - 1;
		while (h - l > 1) {
			int mid = (h + l) / 2;
			int midInd = inds[winner][mid];
			int s = cntBids(winner, midInd);
			for (int i : people) s += cntBids(i, midInd);
			if (s == n - midInd) h = mid;
			else l = mid;
		}
		cout << winner + 1 << " " << arr[inds[winner][h]] << endl;
	}
	return 0;
}