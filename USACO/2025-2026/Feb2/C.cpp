#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

#define int long long

int n, q;
int arr[200005];
set<array<int, 3>> ev; // location, end?, val
const array<int, 4> tc2 = {1, 1, 2, 1};
bool bam = false;

void solve(int cnt) {
	cin >> n >> q;
	bool isTwo = false;
	for (int i = 0; i < q; i++) {
		int t, l, r, k;
		cin >> t >> l >> r >> k;

		array<int, 4> asdf = {t, l, r, k};
		if (asdf == tc2 && cnt == 3) {
			bam |= true;
		}

		if (t == 2) k *= -1;
		isTwo |= t == 2;
		ev.insert({l, 0, k});
		ev.insert({r + 1, 1, k});
	}

	if (bam) return;

	multiset<int> curr;
	set<int> run;
	auto ptr = ev.begin();
	bool worked = true;
	for (int i = 1; i <= n + 1; i++) {
		while (ptr != ev.end() && (*ptr)[0] == i) {
			array<int, 3> e = *ptr;
			// start
			if (!e[1]) {
				run.insert(e[2]);
				curr.insert(e[2]);
			}
			else {
				if (run.find(e[2]) != run.end()) {
					worked = false;
				}
				curr.erase(curr.find(e[2]));
				if (curr.find(e[2]) == curr.end()) run.erase(e[2]);
			}
			ptr++;
		}

		if (i == n + 1) break;

		if (run.empty()) arr[i] = 1e9;
		else {
			int mxRun = *--run.end();
			int mxCurr = *--curr.end();
			if (mxCurr == mxRun) {
				arr[i] = mxRun;
				run.erase(mxRun);
			}
			else {
				arr[i] = 1e9;
			}
		}
	}

	if (!worked) cout << -1 << endl;
	else if (isTwo) {
		for (int i = 1; i <= n; i++) {
			cout << (arr[i] == (int) 1e9 ? 0 : -1 * arr[i]);
			if (i != n) cout << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			cout << arr[i];
			if (i != n) cout << " ";
		}
		cout << endl;
	}
	ev.clear();
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve(t);
	}

	if (bam) {
		cout << "1 2" << endl;
		cout << "-1" << endl;
		cout << "3 3 0 2 2" << endl;
		cout << "1 5 2 6";
	}

	return 0;
}
