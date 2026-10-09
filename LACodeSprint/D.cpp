//
// Created by JMKov on 5/18/2024.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

bool explored[200004];
int dist[200004];
int nxt[200004];
int back[200004];

void dfs(int pos) {
    if (explored[pos]) return;
    explored[pos] = true;
    if (nxt[pos] == -1) return;
    dfs(nxt[pos]);
    dist[pos] = dist[nxt[pos]] + 1;
}

int main() {
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        back[i] = -1;
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) nxt[i] = -1;
    stack<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first < arr[i].second) {
            nxt[st.top().second] = i;
            st.pop();
        }
        st.push({arr[i].second, i});
    }

    for (int i = 0; i < n; i++) back[i] = -1;
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().first > arr[i].second) {
            back[st.top().second] = i;
            st.pop();
        }
        st.push({arr[i].second, i});
    }

    for (int i = 0; i < n; i++) {
        explored[i] = false;
        dist[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        dfs(i);
    }

    for (pair<int, int> p : arr) cout << p.first << " " << p.second << endl;
    cout << endl;
//    for (int i = 0; i < n; i++) cout << dist[i] << " ";
//    cout << endl;
//    for (int i = 0; i < n; i++) cout << back[i] << " ";
//    cout << endl;
    int ans = 1000000000;
    for (int i = 0; i < n; i++)
        if (back[i] == -1) ans = min(ans, dist[i]);
    cout << ans << endl;
    return 0;
}