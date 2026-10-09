#include <iostream>
#include <set>
using namespace std;

int cnt[30];

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	set<char> curr;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
		curr.insert(s[i]);
	}
	char one = '0';
	for (char c : curr) if (cnt[c - 'a'] == 1) {
		one = c;
		break;
	}
	string ans;
	if (one != '0') {
		ans += one;
		curr.erase(one);
		for (char c : curr) for (int i = 0; i < cnt[c - 'a']; i++) {
			ans += c;
		}
	}
	else if (curr.size() == 1) {
		ans = s;
	}
	else {
		char vals[2];
		vals[0] = *curr.begin();
		vals[1] = *++curr.begin();
		if (cnt[vals[0] - 'a'] - 2 <= n - cnt[vals[0] - 'a'] && cnt[vals[0] - 'a'] >= 2) {
			ans += vals[0];
			ans += vals[0];
			int tot = n - cnt[vals[0] - 'a'];
			cnt[vals[0] - 'a'] -= 2;
			if (cnt[vals[0] - 'a'] == 0) curr.erase(vals[0]);
			while (!curr.empty()) {
				char c = *curr.begin();
				if (tot < cnt[vals[0] - 'a']) c = vals[0];
				if (c == vals[0] && ans[ans.size() - 1] == vals[0]) c = *++curr.begin();

				ans += c;
				cnt[c - 'a']--;
				if (c != vals[0]) tot--;
				if (cnt[c - 'a'] == 0) curr.erase(c);
			}
		}
		else {
			ans += vals[0];
			ans += vals[1];
			cnt[vals[0] - 'a']--;
			cnt[vals[1] - 'a']--;

			bool swap = curr.size() == 2;

			for (char c : curr) {
				if (!swap && c == vals[1] && ans[ans.size() - 1] == vals[0]) {
					char asdf = *curr.upper_bound(c);
					cnt[asdf - 'a']--;
					ans += asdf;
				}
				for (int i = 0; i < cnt[c - 'a']; i++) {
					if ((c == vals[0] || c == vals[1]) && swap) {
						for (int i = 0; i < cnt[vals[1] - 'a']; i++) ans += vals[1];
						for (int i = 0; i < cnt[vals[0] - 'a']; i++) ans += vals[0];
						cnt[vals[0] - 'a'] = 0;
						cnt[vals[1] - 'a'] = 0;
						continue;
					}
					ans += c;
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < 30; i++) cnt[i] = 0;
	
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