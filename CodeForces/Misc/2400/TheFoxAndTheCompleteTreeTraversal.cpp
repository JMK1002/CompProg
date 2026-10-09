// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 200100;

std::vector<int> g[N];
int d[N], par[N];
bool onDiameter[N];

void dfs(int v, int p, int depth) {
	d[v] = depth;
	par[v] = p;

	for (auto to : g[v]) {
		if (to != p) {
			dfs(to, v, depth + 1);
		}
	}
}

void run() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i) {
		int from, to;
		scanf("%d%d", &from, &to);
		g[from - 1].push_back(to - 1);
		g[to - 1].push_back(from - 1);
	}

	dfs(0, 0, 0);
	int v1 = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] > d[v1]) {
			v1 = i;
		}
	}

	dfs(v1, v1, 0);
	int v2 = v1;
	for (int i = 0; i < n; ++i) {
		if (d[i] > d[v2]) {
			v2 = i;
		}
	}

	std::vector<int> diameter;
	for (int v = v2; v != v1; v = par[v]) {
		onDiameter[v] = true;
		diameter.push_back(v);
	}
	onDiameter[v1] = true;
	diameter.push_back(v1);
	std::reverse(diameter.begin(), diameter.end());

	for (int i = 0; i < n; ++i) {
		if (onDiameter[i]) {
			continue;
		}
		if (!onDiameter[par[i]]) {
			printf("No\n");
			return;
		}
	}

	printf("Yes\n");
	std::vector<int> ans;
	for (int i = 0; i < (int)diameter.size(); i += 2) {
		ans.push_back(diameter[i]);
		if (i + 1 != (int)diameter.size()) {
			for (auto to : g[diameter[i + 1]]) {
				if (!onDiameter[to]) {
					ans.push_back(to);
				}
			}
		}
	}

	if (diameter.size() % 2 == 0) {
		for (int i = (int)diameter.size() - 1; i > 0; i -= 2) {
			ans.push_back(diameter[i]);
			if (i - 1 >= 0) {
				for (auto to : g[diameter[i - 1]]) {
					if (!onDiameter[to]) {
						ans.push_back(to);
					}
				}
			}
		}
	} else {
		for (int i = (int)diameter.size() - 1; i > 0; i -= 2) {
			ans.push_back(diameter[i - 1]);
			if (i - 2 >= 0) {
				for (auto to : g[diameter[i - 2]]) {
					if (!onDiameter[to]) {
						ans.push_back(to);
					}
				}
			}
		}
	}

	assert((int)ans.size() == n);
	for (auto i : ans) {
		printf("%d ", i + 1);
	}
	printf("\n");
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    #ifdef PERVEEVM_LOCAL
        auto start = std::chrono::high_resolution_clock::now();
    #endif

    run();

    #ifdef PERVEEVM_LOCAL
        auto end = std::chrono::high_resolution_clock::now();
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}
