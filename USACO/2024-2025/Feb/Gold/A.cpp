#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

long long n;
long long arr[200005];
long long dp[200005][2];
set<long long> rev[200005];
bool explored[200005];
long long c[200005];
vector<long long> topo;

void dfs(long long v) {
	explored[v] = true;
	dp[v][0] = 0;
	dp[v][1] = 0;
	for (long long e : rev[v]) {
		if (e == v) continue;
		dfs(e);
	}
	topo.push_back(v);
}

// Node v is looped and the end of the DAG
long long solve(long long v) {
	topo.clear();
	dfs(v);
	for (long long curr : topo) {
		dp[curr][1] += c[curr] * (curr != arr[curr]);
		for (long long child : rev[curr]) {
			dp[curr][0] += dp[child][1];
			dp[curr][1] += min(dp[child][0], dp[child][1]);
		}
	}
	return dp[v][1];
}

int main() {
	// ! Idea is reverse greedy, find all "necessary" edges and then make everything a loop
	// ! Sort best to re add to worst
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	for (long long i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (long long i = 0; i < n; i++) {
		rev[arr[i]].insert(i);
	}

	// Tortoise and hare
	long long asdf = 0;
	for (long long i = 0; i < n; i++) {
		if (explored[i]) continue;
		long long a = i;
		long long b = arr[i];
		while (a != b) {
			a = arr[a];
			b = arr[arr[b]];
		}
		long long act = arr[a];
		arr[a] = a;
		rev[act].erase(a);
		long long ans = solve(a) + c[a] * (a != act);
		rev[act].insert(a);
		arr[a] = act;
		a = arr[a];

		act = arr[a];
		arr[a] = a;
		rev[act].erase(a);
		ans = min(ans, solve(a) + c[a] * (a != act));
		rev[act].insert(a);
		arr[a] = act;
		asdf += ans;
	}
	cout << asdf << endl;
	return 0;
}
// 5
// 2 4 4 4 3
// 1 1 1 1 1