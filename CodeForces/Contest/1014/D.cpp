#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
vector<int> arr; // T is 0, I is 1, L is 2
vector<int> ans;
pair<int, int> cnt[3];

int missing(int a, int b) {
	if (b < a) swap(a, b);
	if (a == 0 && b == 1) return 2;
	if (a == 1 && b == 2) return 0;
	if (a == 0 && b == 2) return 1;
	else return -1;
}

void add(int i) {
	int thing = missing(arr[i], arr[i + 1]);
	arr.insert(arr.begin() + (i + 1), thing);
	cnt[thing].first++;
	ans.push_back(i);
}

void clean() {
	s.clear();
	arr.clear();
	ans.clear();
	for (int i = 0; i < 3; i++) cnt[i] = {0, i};
}

void addK(int a, int b, int k) {
	int undesired = missing(a, b);
	bool done = false;
	for (int i = 0; !done && i < arr.size() - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			int ms = missing(arr[i], arr[i + 1]);
			if (ms == undesired) continue;
			// ! ms is either mx or mn
			int desired = (ms == a) ? b : a;
			// ! desired + ms
			int amnt = k;
			if (desired == arr[i]) {
				for (int j = i; j < 2 * amnt + i; j++) {
					add(j);
					done = true;
				}
			}
			else { // ! diesired == arr[i + 1]
				for (int j = i; j < 2 * amnt + i; j++) {
					add(i);
					done = true;
				}
			}
		}
	}
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < 3; i++) cnt[i] = {0, i};
	for (int i = 0; i < n; i++) {
		int v = (s[i] == 'T') ? 0 : ((s[i] == 'I') ? 1 : 2);
		arr.push_back(v);
		cnt[v].first++;
	}

	int asdf = 0;
	for (int i = 0; i < 3; i++) asdf += cnt[i].first;
	if (asdf == max(cnt[0], max(cnt[1], cnt[2])).first) {
		cout << -1 << endl;
		return;
	}

	pair<int, int> mn = min(cnt[0], min(cnt[1], cnt[2]));
	pair<int, int> mx = max(cnt[0], max(cnt[1], cnt[2]));
	pair<int, int> md = cnt[missing(mn.second, mx.second)];
	addK(mx.second, mn.second, md.first - mn.first);
	mn = min(cnt[0], min(cnt[1], cnt[2]));
	mx = max(cnt[0], max(cnt[1], cnt[2]));
	md = cnt[missing(mn.second, mx.second)];
	addK(md.second, mn.second, mx.first - md.first);
	bool worked = true;
	for (int i = 0; i < 3; i++) {
		worked &= cnt[i].first == cnt[0].first;
		// cout << cnt[i].first << endl;
	}
	if (!worked) cout << "ERR" << endl;
	cout << ans.size() << endl;
	for (int i : ans) cout << i + 1 << endl;
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
		clean();
	}
	return 0;
}