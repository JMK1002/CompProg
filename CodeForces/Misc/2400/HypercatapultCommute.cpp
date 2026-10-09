#include <bits/stdc++.h>
#define int long long 
#define endl '\n' 
using namespace std;
const int  N = 1005;
int f[N];
int ran[N];
void init(int n) {
	for (int i = 0; i <= n; i++) {
		f[i] = i;
		ran[i] = 1;
	}
}

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool isSame(int x, int y) {
	return find(x) == find(y);
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (ran[x] > ran[y])
		f[y] = x;
	else {
		if (ran[x] == ran[y]) ran[y]++;
		f[x] = y;
	}
	return true;
}
vector<int>z[N];

vector<int>e[N];
int du[N];
int d[N];
int vis[N];
queue<int> toposort(vector<int>t) {
	queue <int> Q;
	queue <int> ans;
	for (int i : t) {
		if (du[i] == 0) {
			Q.push(i);
			ans.push(i);
		}
	}
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i : e[x]) {
			du[i]--;
			if (du[i] == 0) {
				Q.push(i);
				ans.push(i);
			}
		}
	}
	return ans;
}

queue<int> toposort1(vector<int>t,int s) {
	queue <int> Q;
	queue <int> ans;
	Q.push(s);
	ans.push(s);
	vis[s] = 1;
	for (int i : t) {
		if (du[i] == 0) {
			Q.push(i);
			ans.push(i);
		}
	}
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (int i : e[x]) {
			du[i]--;
			if (du[i] == 0&&!vis[i]) {
				vis[i] = 1;
				Q.push(i);
				ans.push(i);
			}
		}
	}
	return ans;
}
signed main() {
	int n, m;
	cin >> n >> m;
	init(n);
	for (int i = 1;i <= m;i++) {
		int u, v;
		cin >> u >> v;
		join(u, v);
		e[u].push_back(v);
		d[v]++;
		du[v]++;
	}
	for (int i = 1;i <= n;i++) {
		z[find(i)].push_back(i);
	}
	vector<pair<int,int>>ans;
	for (int i = 1;i <= n;i++) {
		if (z[i].empty())
			continue;
		queue<int>aaa = toposort(z[i]);
		if (aaa.size() == z[i].size()) {
			int las = aaa.front();
			aaa.pop();
			while (!aaa.empty()) {
				ans.push_back({ las,aaa.front() });
				las = aaa.front();
				aaa.pop();
			}
		}
		else {
			int fff = 0;
			for (int j : z[i]) {
				for (int k : z[i]) {
					du[k] = d[k];
					vis[k] = 0;
				}
				auto zz=toposort1(z[i], j);
				if (zz.size() == z[i].size()) {
					fff = 1;
					int las = zz.front();
					zz.pop();
					while (!zz.empty()) {
						ans.push_back({ las,zz.front() });
						las = zz.front();
						zz.pop();
					}
					ans.push_back({ las,j });
					break;
				}
			}
			if (fff)
				continue;
			else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}