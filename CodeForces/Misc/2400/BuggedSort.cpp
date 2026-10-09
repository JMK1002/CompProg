#include <iostream>
using namespace std;

int n;
pair<int, int> arr[400005];
int inv[400005];
bool explored[400005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		inv[arr[i].first] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
		inv[arr[i].second] = i;
	}
	pair<int, int> mx = {0, 0};
	int rev = 0;
	int both = 0;
	int cnt = 0;
	bool oddExists = false;
	for (int i = 1; i <= 2 * n; i++) {
		if (explored[inv[i]]) continue;
		explored[inv[i]] = true;
		pair<int, int> p = arr[inv[i]];
		bool a = mx.first < p.first && mx.second < p.second;
		bool b = mx.first < p.second && mx.second < p.first;
		if (!a && !b) {
			cout << "NO" << endl;
			return;
		}
		both += (a && b);
		if (a) mx = {p.first, p.second};
		if (b) {
			mx = {p.second, p.first};
			rev++;
		}
		if (a && b) {
			if (cnt % 2 == 1) oddExists = true;
			cnt = 0;
		}
		cnt++;
	}
	if (cnt % 2 == 1) oddExists = true;
	if (!oddExists && rev % 2 == 1) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 0; i <= 2 * n; i++) {
		inv[i] = 0;
		explored[i] = false;
		arr[i] = {0, 0};
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= 2 * n; i++) {
			inv[i] = 0;
			explored[i] = false;
			arr[i] = {0, 0};
		}
	}
	return 0;
}