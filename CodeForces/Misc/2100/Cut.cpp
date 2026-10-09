//
// Created by JMKov on 8/17/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
const int bt = 30;
int arr[100004];
int pt[100004];
vector<int> adj[100004];
int up[100005][bt];

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < bt; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int edge : adj[v]) {
        dfs(edge, v);
    }
}

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < bt; j++) {
            up[i][j] = n;
        }
    }
    dfs(n, n);
}

int calc(int st, int end) {
    int ans = 0;
    for (int i = bt - 1; i >= 0; i--) {
        if (up[st][i] <= end) {
            st = up[st][i];
            ans += (1 << i);
        }
    }
    return ans + 1;
}

vector<int> sieve(int c) {
    vector<int> ret;
    bool marked[c + 2];
    for (bool & i : marked) i = false;
    for (int i = 2; i <= c; i++) {
        if (marked[i]) continue;
        ret.push_back(i);
        for (int j = i; j <= c; j += i) {
            marked[j] = true;
        }
    }
    return ret;
}

vector<int> factor(int v, const vector<int>& primes) {
    vector<int> ret;
    for (int i = 0; primes[i] * primes[i] <= v; i++) {
        if (v % primes[i] == 0) ret.push_back(i);
        while (v % primes[i] == 0) {
            v /= primes[i];
        }
    }
    if (v != 1) {
        ret.push_back(distance(primes.begin(), lower_bound(primes.begin(), primes.end(), v)));
    }
    return ret;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ptr = 0;
    vector<int> primes = sieve(100000);
    bool inProduct[primes.size()];
    for (bool & i : inProduct) i = false;
    for (int i = 0; i < n; i++) {
        bool cont = true;
        while (cont && ptr < n) {
            vector<int> fact = factor(arr[ptr], primes);
            for (int j : fact) if (inProduct[j]) {
                cont = false;
                break;
            }
            if (!cont) break;
            for (int j : fact) inProduct[j] = true;
//            for (int j : fact) cout << j << " ";
//            cout << endl;
//            cout << arr[ptr] << endl;
            ptr++;
        }
        pt[i] = ptr;
        adj[ptr].push_back(i);
        vector<int> fact = factor(arr[i], primes);
        for (int j : fact) inProduct[j] = false;
    }
//    for (int i = 0; i < n; i++) cout << pt[i] << " ";
//    cout << endl;
    init();
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << calc(l, r) << endl;
    }
    return 0;
}