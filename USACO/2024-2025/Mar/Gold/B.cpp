#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

int n, q;
int arr[200005];
int in[200005];
multiset<int> sortedIn;
set<int> ind[200005];
vector<int> sequence;
pair<int, int> t[1000000]; // ! THIS IS THE LAST MAX

// {first index where i appears, last index where i appears}

pair<int, int> op(pair<int, int> a, pair<int, int> b) {
	return {min(a.first, b.first), max(a.second, b.second)};
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) return {1500000000, 0};
    else if (l == tl && r == tr) {
		return t[v];
	}
	else {
		int tm = (tl + tr) / 2;
		return op(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
}

void update(int v, int tl, int tr, int ind, pair<int, int> val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (ind <= tm) update(v*2, tl, tm, ind, val);
        else update(v*2+1, tm+1, tr, ind, val);
        t[v] = op(t[v*2], t[v*2+1]);
    }
}

// ! EVERYTHING IS ONE INDEXED

void getSequence() {
	sequence.clear();
	// stack<int> st;
	// for (int i = 1; i <= n; i++) {
	// 	while (!st.empty() && in[i] > st.top()) st.pop();
	// 	st.push(in[i]);
	// 	if (st.size() == 1 && in[i] != 0) sequence.push_back(i);
	// }
	int ptr = query(1, 0, n, 1, n).first;
	while (ptr != 1500000000) {
		sequence.push_back(ptr);
		ptr = query(1, 0, n, in[ptr] + 1, n).first;
	}
}

int inMx() {
	return *--sortedIn.end();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		in[arr[i]]++;
	}
	// for (int i = 1; i <= n; i++) cin >> in[i];
	for (int i = 1; i <= n; i++) {
		ind[in[i]].insert(i);
		sortedIn.insert(in[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (ind[i].empty()) update(1, 0, n, i, {1500000000, -1});
		else update(1, 0, n, i, {*ind[i].begin(), *--ind[i].end()});
	}

	getSequence();

	while (q--) {
		int a, b;
		cin >> a >> b;
		int prev = arr[a];
		arr[a] = b;

		sortedIn.erase(sortedIn.find(in[b]));
		ind[in[b]].erase(b);
		in[b]++;
		ind[in[b]].insert(b);
		sortedIn.insert(in[b]);
		
		sortedIn.erase(sortedIn.find(in[prev]));
		ind[in[prev]].erase(prev);
		in[prev]--;
		ind[in[prev]].insert(prev);
		sortedIn.insert(in[prev]);
		
		set<int> temp = {in[b], in[b] - 1, in[prev], in[prev] + 1};
		for (int i : temp) {
			if (ind[i].empty()) update(1, 0, n, i, {1500000000, -1});
			else update(1, 0, n, i, {*ind[i].begin(), *--ind[i].end()});
		}

		getSequence();

		int mx = inMx();
		int ans = 0;
		for (int i : sequence) {
			int x = query(1, 0, n, max(1, mx - in[i]), n).second;
			if (x == -1) continue;
			ans = max(ans, x - i);
		}
		cout << ans << endl;
	}
	
	return 0;
}
// 10 0
// 4 10 2 2 3 6 1 10 8 6

// 10 0
// 1 2 1 1 0 3 0 1 0 2

// 5 3
// 2 2 4 4 2