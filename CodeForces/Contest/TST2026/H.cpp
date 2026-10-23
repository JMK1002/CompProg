#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[2005];

char query(int x) {
	cout << "? " << x << endl;
	cout.flush();
	char res;
	cin >> res;
	return res;
}

void findMed(vector<int> inds, int minElement) {
	if (inds.empty()) return;
	if (inds.size() == 1) {
		arr[inds[0]] = minElement;
		return;
	}

	// finding minElement
	while (query(inds[0]) != '=') continue;
	int lstDown = inds[0];
	for (int i = 1; i < inds.size(); i++) {
		char c = query(inds[i]);
		if (c == '>') query(lstDown);
		else if (c == '<') {
			lstDown = inds[i];
			while (query(lstDown) != '=') continue;
		}
		else {
			cout << "ERROR, IMPOSSIBLE CASE!" << endl;
		}
	}

	// lstDown is index of minElement
	arr[lstDown] = minElement;

	// finding maxElement
	while (query(inds[0]) != '=') continue;
	int lstUp = inds[0];
	for (int i = 1; i < inds.size(); i++) {
		char c = query(inds[i]);
		if (c == '<') query(lstUp);
		else if (c == '>') {
			lstUp = inds[i];
			while (query(lstUp) != '=') continue;
		}
		else {
			cout << "ERROR, IMPOSSIBLE CASE!" << endl;
		}
	}

	// lstUp is index of maxElement
	int maxElement = minElement + inds.size() - 1;
	arr[lstUp] = maxElement;

	int x = maxElement;
	int target = minElement + inds.size() / 2;

	for (int i = 0; i < inds.size() && x != target; i++) {
		char c = query(inds[i]);
		if (c == '<') x--;
		else if (c == '>') x++;

		while (x != target && c == '<') {
			c = query(inds[i]);
			if (c == '<') x--;
			else if (c == '>') x++;
		}
	}

	vector<int> low;
	vector<int> high;
	for (int i = 0; i < inds.size(); i++) {
		char c = query(inds[i]);
		if (c == '<') {
			low.push_back(inds[i]);
			query(lstUp);
		}
		else if (c == '>') {
			high.push_back(inds[i]);
			query(lstDown);
		}
		else {
			arr[inds[i]] = target;
		}
	}
	findMed(low, minElement);
	findMed(high, target + 1);
}

void solve() {
	cin >> n;
	vector<int> all;
	for (int i = 1; i <= n; i++) all.push_back(i);
	findMed(all, 1);
	cout << "! ";
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout.flush();
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
//! 3 4 1 6 3
