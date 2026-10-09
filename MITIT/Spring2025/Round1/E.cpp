#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, r;
string s;
bool arr[405];

void doComputerMove() {
	cin >> s;
	for (int i = 0; i < n; i++) arr[i] = s[i] == '1';
	l = 0; r = n - 1;
	while (l < n && arr[l] == 0) l++;
	while (r >= 0 && arr[r] == 1) r--;
}

vector<int> countRange(int a, int b) {
	vector<int> res = {0, 0};
	for (int i = a; i <= b; i++) {
		res[arr[i]]++;
	}
	return res;
}

void doEndMove() {
	if (arr[l + 1] == 0) {
		cout << "2 " << l << " " << r - 1 << endl;
	}
	else {
		cout << "2 " << l + 1 << " " << r << endl;
	}
	cout.flush();
}

int getSwaps(int a, int b) {
	int swaps = 0;
	for (int i = a + 1; i <= b; i++) {
		swaps += (arr[i] != arr[i - 1]);
	}
	return swaps;
}

void solve() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) arr[i] = s[i] == '1';
	l = 0; r = n - 1;
	while (l < n && arr[l] == 0) l++;
	while (r >= 0 && arr[r] == 1) r--;

	if (l > r || l == r - 1) { // ? if sorted or if just one swap
		cout << "Second" << endl;
		cout.flush();
		return;
	}

	if (v[0] == 0 || v[1] == 0) {
		cout << "First" << endl;
		doEndMove();
		cout.flush();
	}
	
	while (true) {
		vector<int> v = countRange(l + 1, r - 1);
		if (v[0] == 0 || v[1] == 0) {
			cout << "First" << endl;
			doEndMove();
			cout.flush();
		}
		else {
			if (getSwaps(l, r) == 3 && getSwaps(l + 1, r - 1) == 1) {

			}
			else {
				cout << (r - l - 1) << " ";
				for (int i = l + 1; i <= r - 1; i++) cout << i << " ";
				cout << endl;
				cout.flush();
			}
		}
	}
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