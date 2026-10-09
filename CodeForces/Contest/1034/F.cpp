#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int n;
map<int, vector<int>> asdf;
bool added[100005];
int thing[100005];
int ans[100005];

void solve() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (added[i]) continue;
		if (i <= n / 2) {
			added[i] = true;
			added[2 * i] = true;
			thing[i] = i;
			thing[2 * i] = i;
			asdf[i].push_back(i);
			asdf[i].push_back(2 * i);
			continue;
		}

		bool prime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				asdf[j].push_back(i);
				added[i] = true;
				thing[i] = j;
				prime = false;
				break;
			}
		}
		if (prime) {
			asdf[i].push_back(i);
			added[i] = true;
			thing[i] = i;
		}
	}
	ans[1] = 1;
	for (pair<int, vector<int>> p : asdf) {
		for (int i = 0; i < p.second.size(); i++) {
			ans[p.second[(i + 1) % p.second.size()]] = p.second[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		added[i] = 0;
		thing[i] = 0;
		ans[i] = 0;
	} 
	asdf.clear();
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