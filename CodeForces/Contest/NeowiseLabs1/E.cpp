#include <iostream>
using namespace std;

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i+= 2) cout << s[i];
	cout << endl;
	for (int i = 1; i < s.size(); i+= 2) cout << s[i];
	cout << endl;
	return 0;
}
// BPBPBBBBBPBBBBB
// PBPB