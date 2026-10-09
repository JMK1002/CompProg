//
// Created by JMKov on 7/19/2023.
//
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    bool reachable[m];
    for (int i = 0; i < m; i++) reachable[i] = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(arr[i]);
        for (int j = 0; j < m; j++) {
            if (reachable[j + m * (j < arr[i]) - arr[i]]) q.push(j);
        }
        while (!q.empty()) {
            reachable[q.front()] = true;
            q.pop();
        }
        if (reachable[0]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}