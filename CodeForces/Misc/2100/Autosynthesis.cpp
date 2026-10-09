//
// Created by JMKov on 7/5/2024.
//
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[200005];
set<int> adj[200005];
set<int> radj[200005];
int in[200005];
bool ans[200005];
bool explored[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        adj[i].insert(arr[i]);
        radj[arr[i]].insert(i);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        in[i] = radj[i].size();
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        explored[v] = true;
        ans[v] = true;
        for (int e : radj[v]) if (ans[e]) {
            ans[v] = false;
            break;
        }
        in[arr[v]]--;
        if (in[arr[v]] == 0) q.push(arr[v]);
    }
    for (int i = 0; i < n; i++) {
        if (explored[i]) continue;
        explored[i] = true;
        for (int j = 0; j < 2; j++) {
            ans[i] = true;
            for (int e: radj[i]) {
                if (ans[e]) {
                    ans[i] = false;
                    break;
                }
            }

            int a = arr[i];
            while (a != i) {
                explored[a] = true;
                ans[a] = true;
                for (int e: radj[a]) {
                    if (ans[e]) {
                        ans[a] = false;
                        break;
                    }
                }
                a = arr[a];
            }
        }
        bool x = true;
        for (int e: radj[i]) {
            if (ans[e]) {
                x = false;
                break;
            }
        }
        if (x != ans[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += ans[i];
    cout << cnt << endl;
    for (int i = 0; i < n; i++) if (ans[i]) cout << arr[i] + 1 << " ";
    cout << endl;
    return 0;
}