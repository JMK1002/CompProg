#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, q;
int arr[200005];
int cnt[200050];
set<pair<int, int>> rngs;

void merge(auto ptr) {
	if (ptr == rngs.begin()) return;
	pair<int, int> p1 = *ptr;
	ptr--;
	pair<int, int> p2 = *ptr;
	if (p2.second + 1 == p1.first) {
		rngs.erase(p1);
		rngs.erase(p2);
		rngs.insert({p2.first, p1.second});
	}
}

void subtract(int x) {
	auto ptr = rngs.lower_bound({x, 1e9});
	bool in;
	if (ptr != rngs.begin()) {
		--ptr;
		in = (ptr->first <= x && x <= ptr->second);
		ptr++;
	}
	else in = false;

	pair<int, int> p1;
	pair<int, int> p2;
	if (in) {
		--ptr;
		p1 = {ptr->first, x - 1};
		p2 = {x + 1, ptr->second};
	}
	else {
		p1 = {x, ptr->first - 1};
		p2 = {ptr->first + 1, ptr->second};
	}
	rngs.erase(ptr);
	if (p1.first <= p1.second) rngs.insert(p1);
	if (p2.first <= p2.second) rngs.insert(p2);

	merge(rngs.lower_bound(p1));
	merge(rngs.upper_bound(p2));
}

void add(int x) {
	auto ptr = rngs.lower_bound({x, 1e9});
	bool in;
	if (ptr != rngs.begin()) {
		--ptr;
		in = (ptr->first <= x && x <= ptr->second);
		ptr++;
	}
	else in = false;

	pair<int, int> p1;
	pair<int, int> p2;
	if (in) {
		ptr--;
		p1 = {ptr->first, x - 1};
		p2 = {ptr->second + 1, ptr->second + 1};
	}
	else if (!in && ptr == rngs.end()) {
		rngs.insert({x, x});
		merge(rngs.lower_bound({x, x}));
		return;
	}
	else {
		p1 = {x, x};
		p2 = {ptr->first, ptr->second};
	}
	rngs.erase(ptr);
	if (p1.first <= p1.second) rngs.insert(p1);
	if (p2.first <= p2.second) rngs.insert(p2);

	merge(rngs.lower_bound(p1));
	merge(rngs.upper_bound(p1));
	merge(rngs.upper_bound(p2));
}

void get() {
	int n = (--rngs.end())->second;
	vector<int> v(n + 2, 0);
	for (pair<int, int> p : rngs) {
		for (int i = p.first; i <= p.second; i++) v[i] = 1;
	}
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << endl;
}

void solve() {
	cin >> n >> q;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		cnt[arr[i]]++;
	}
	for (int i = 0; i <= mx; i++) {
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
		if (cnt[i + 1]) mx = max(mx, i + 1);
		if (cnt[i]) add(i);
	}
	// get();
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		subtract(arr[a]);
		add(b);
		arr[a] = b;
		// get();
		cout << (--rngs.end())->second << endl;
	}
} 

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}