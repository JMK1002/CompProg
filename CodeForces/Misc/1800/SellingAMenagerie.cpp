//
// Created by JMKov on 4/20/2024.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;



const long long INF = INT64_MAX;

long long n;
long long arr[100005];
long long c[100005];
bool explored[100005];
set<int> radj[100005];
vector<int> ans;
bool explored2[100005];

void dfs(int v) {
    explored2[v] = true;
    for (int e : radj[v]) {
        if (explored2[e]) continue;
        dfs(e);
    }
    ans.push_back(v);
}

long long cycle(long long v) {
    long long a = v;
    long long b = arr[v];
    while (a != b && !explored[a]) {
        explored[a] = true;
        a = arr[a];
        b = arr[arr[b]];
    }
    if (explored[a]) return 0;
    b = arr[a];
    vector<long long> ret;
    ret.push_back(a);
    explored[a] = true;
    while (a != b) {
        explored[b] = true;
        ret.push_back(b);
        b = arr[b];
    }
    long long mn = INF;
    int ind = -1;
    for (long long i : ret) {
        if (c[i] < mn) {
            mn = c[i];
            ind = i;
        }
    }
    dfs(ind);
    return mn;
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        radj[arr[i]].insert(i);
    }
    long long s = 0;
    for (long long i = 0; i < n; i++) {
        cin >> c[i];
        s += 2 * c[i];
    }
    for (long long i = 0; i < n; i++) {
        s -= cycle(i);
    }
    for (int i : ans) cout << i + 1 << " ";
    cout << endl;
    for (long long i = 0; i < n; i++) {
        explored[i] = false;
        explored2[i] = false;
        radj[i].clear();
    }
    ans.clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}