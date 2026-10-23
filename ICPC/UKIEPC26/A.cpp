#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(26, {0, 0});
	for (int i = 0; i < 26; i++) {
		v[i].second = i;
	}
	string res = "";
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		res += s + " ";
		for (char c : s) v[c - 'a'].first++;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < res.size(); i++) {
		bool dontReplace = false;
		for (int j = 0; j < k; j++) {
			if (res[i] - 'a' == v[j].second) {
				dontReplace = true;
				break;
			}
		}
		if (!dontReplace && res[i] != ' ') res[i] = 'a' + v[0].second;
	}
	cout << res << endl;
	return 0;
}
