#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

long long n;
pair<long long, long long> arr[200005];
vector<int> vals[2];
set<pair<int, int>> asdf[2];
int cnt = 1;

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	long long ans = 0;
	for (long long j = 0; j < 2; j++) {
		sort(arr, arr + n);
		long long v = 1;
		for (long long i = 0; i < n; i++) {
			if (v > arr[i].first) {
				if ((--asdf[j].end())->first > arr[i].second) {
					pair<int, int> p = *--asdf[j].end();
					asdf[j].erase(p);
					asdf[j].insert({arr[i].second, p.second});
				}
				continue;
			}
			asdf[j].insert({arr[i].second, v});
			v++;
		}

		for (long long i = 0; i < n; i++) arr[i].second *= -1;
	}
	long long run = 0;
	auto p1 = asdf[0].begin();
	auto p2 = asdf[1].begin();
	for (int i = 0; i < asdf[0].size(); i++) {
		run -= (*p1).first + (*p2).first;
		ans = max(run, ans);
		p1++; p2++;
	}
	cout << ans << endl;
	for (long long i = 0; i < n; i++) arr[i] = {0, 0};
	asdf[0].clear();
	asdf[1].clear();
	cnt++;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}