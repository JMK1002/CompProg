#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[3][200005];
array<int, 3> coords[200005];



array<int, 3> getCoords(array<int, 3> val) {
	int x = val[0];
	int y = val[1];
	int z = val[2];

	if (z == 0 || z == 1) return {x, y, x + y};
	else if (z == 2 || z == 3) return {x - 1, y, x + y};
	else if (z == 4 || z == 5) return {x - 1, y, x + y - 1};
	else if (z == 6 || z == 7) return {x - 1, y - 1, x + y - 1};
	else if (z == 8 || z == 9) return {x, y - 1, x + y - 1};
	else return {x, y - 1, x + y};
}

int getOppositeZ(int z) {
	return ((((z + 1) % 12) ^ 1) - 1 + 12) % 12;
}

int getRawDist(array<int, 3> a, array<int, 3> b) {
	int ans = 0;
	for (int x = 0; x < 3; x++) {
		ans += abs(a[x] - b[x]);
	}
	return ans;
}

int getDist(int a, int b) {
	int ans = 1e9;
	vector<int> res;
	for (int i = 0; i < 4; i++) {
		array<int, 3> aUnconverted = {arr[0][a], arr[1][a], (i & 1) ? getOppositeZ(arr[2][a]) : arr[2][a]};
		array<int, 3> bUnconverted = {arr[0][b], arr[1][b], ((i / 2) & 1) ? getOppositeZ(arr[2][b]) : arr[2][b]};

		array<int, 3> aCoords = getCoords(aUnconverted);
		array<int, 3> bCoords = getCoords(bUnconverted);

		if (aUnconverted == bUnconverted) ans = min(ans, (long long) __builtin_popcount(i));
		else ans = min(ans, __builtin_popcount(i) + 2 * getRawDist(aCoords, bCoords) + 1);
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 5 || z == 6) x--;
		else if (z == 7 || z == 8) y--;
		else if (z == 9 || z == 10) {
			x++; y--;
		}

		if (z >= 5 && z <= 10 && z % 2) z -= 5;
		else if (z >= 5 && z <= 10) z = (z + 5) % 12;

		arr[0][i] = x;
		arr[1][i] = y;
		arr[2][i] = z;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		ans += getDist(i, j);
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		coords[i] = {0, 0, 0};
		for (int j = 0; j < 3; j++) arr[j][i] = 0;
	}
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
