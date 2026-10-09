#include <iostream>
#include <set>
using namespace std;

int n, q;
set<int> people;
set<pair<int, int>> earliest;

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	people.insert(-1e9);
	people.insert(1e9);
	for (int i = 1; i <= n; i++) people.insert(i);
	earliest.insert({1e9, 1e9});
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int l, r, x;
			cin >> l >> r >> x;
			if (x == 0) {
				while (*people.lower_bound(l) <= r) {
					people.erase(people.lower_bound(l));
				}
			}
			else {
				auto ptr = earliest.lower_bound({l, -1e9});
				if (r >= ptr->second) continue;

				ptr = earliest.lower_bound({l, 1e9});
				while (ptr != earliest.begin() && (--ptr)->second >= r) {
					earliest.erase(ptr);
					ptr = earliest.lower_bound({l, 1e9});
				}
				earliest.insert({l, r});
			}
		}
		else {
			int x;
			cin >> x;
			if (people.find(x) == people.end()) {
				cout << "NO" << endl;
				continue;
			}

			int l = (*--people.lower_bound(x)) + 1;
			int r = (*++people.lower_bound(x)) - 1;

			if (earliest.lower_bound({l, -1e9})->second <= r) {
				cout << "YES" << endl;
			}
			else cout << "N/A" << endl;
		}
	}
}