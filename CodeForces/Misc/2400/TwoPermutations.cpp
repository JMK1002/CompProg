#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n[2];
vector<int> arr[2];
vector<int> ans[2];

void swapArr(int a, int b, bool j) {
	if (b < a) swap(a, b);
	swap(arr[j][a], arr[j][b]);
	ans[j].push_back(a);
	ans[j].push_back(b - a - 1);
	ans[j].push_back(n[j] - 1 - b);
}

int main() {
	cin >> n[0] >> n[1];
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n[j]; i++) {
			int x;
			cin >> x;
			arr[j].push_back(x);
		}
		for (int i = 0; i < n[j]; i++) {
			int mn = i;
			for (int k = i; k < n[j]; k++) {
				if (arr[j][k] < arr[j][mn]) mn = k;
			}
			if (mn == i) continue;
			swapArr(i, mn, j);
		}
		// for (int i : arr[j]) cout << i << " ";
		// cout << endl;
	}
	if ((ans[0].size() % 2) != (ans[1].size() % 2) && n[0] % 2 == 0 && n[1] % 2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	if ((ans[0].size() % 2) != (ans[1].size() % 2)) {
		int j = (n[0] % 2) ? 0 : 1;
		for (int i = 0; i < n[j]; i++) ans[j].push_back(0);
	}
	int j = (ans[0].size() > ans[1].size());
	while (ans[0].size() != ans[1].size()) {
		ans[j].push_back(0);
		ans[j].push_back(n[j] - 1);
	}
	cout << ans[0].size() << endl;
	for (int i = 0; i < ans[0].size(); i++) {
		cout << ans[0][i] + 1 << " " << ans[1][i] + 1 << endl;
	}
	return 0;
}