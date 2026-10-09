#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int n, k;
int arr[200005];
int sorted[200005];
vector<int> act;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted, sorted + n);
	for (int i = 0; i < n; i++) if (arr[i] <= sorted[k - 1]) act.push_back(arr[i]);
	int l = 0;
	int r = act.size() - 1;
	int cnt = 0;
	bool works = true;
	while (l < r) {
		if (act[l] == act[r]) {
			l++;
			r--;
			continue;
		}
		
		if (act[l] == sorted[k - 1]) {
			l++;
			cnt++;
		}
		else if (act[r] == sorted[k - 1]) {
			r--;
			cnt++;
		}
		else {
			works = false;
			break;
		}
	}

	works &= (act.size() - cnt >= k - 1);
	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		sorted[i] = 0;
	}
	act.clear();
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