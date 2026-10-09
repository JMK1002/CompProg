//
// Created by JMKov on 7/20/2023.
//
#include <iostream>
#include <set>
using namespace std;

set<int> children[300010];
int mxCSz[300010];
int sz[300010];
int ans[300010];
int parent[300010];

void setSize(int v) {
    if (children[v].empty()) {
        sz[v] = 1;
        return;
    }
    sz[v] = 1;
    for (int i : children[v]) {
        setSize(i);
        sz[v] += sz[i];
        mxCSz[v] = max(mxCSz[v], sz[i]);
    }
}

void dfsAns(int v) {
    if (children[v].empty()) {
        ans[v] = v;
        return;
    }
    for (int i : children[v]) {
        dfsAns(i);
        if (ans[v] == 0 || !(sz[v] - sz[ans[v]] <= sz[v] / 2 && mxCSz[ans[v]] <= sz[v] / 2))
            ans[v] = ans[i];
        while (!(sz[v] - sz[ans[v]] <= sz[v] / 2 && mxCSz[ans[v]] <= sz[v] / 2) && ans[v] != v) {
            ans[v] = parent[ans[v]];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    parent[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
//        parent[i] = i;
        parent[i]--;
        children[parent[i]].insert(i);
    }
    setSize(0);
    dfsAns(0);
//    for (int i = 0; i < n; i++) cout << ans[i] << " ";
//    cout << endl;
    while (q--) {
        int v;
        cin >> v;
        v--;
        cout << ans[v] + 1 << endl;
    }
    return 0;
}
//7 4
//1 1 3 3 5 3
//1
//2
//3
//5