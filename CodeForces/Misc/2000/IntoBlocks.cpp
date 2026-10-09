#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int n, q;
int arr[200005];
map<int, int> last;
map<int, int> cnt;
vector<pair<int, int>> ranges;

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		last[arr[i]] = i;
		cnt[arr[i]]++;
	}
	int ans = 0;
	int mx = 0;
	int l = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (i > r) {
			ans += r - l + 1 - mx;
			l = i;
			r = i;
			mx = 0;
		}
		mx = max(mx, cnt[arr[i]]);
		r = max(r, last[arr[i]]);
	}
	ans += r - l + 1 - mx;
	cout << ans << endl;
	return 0;
}