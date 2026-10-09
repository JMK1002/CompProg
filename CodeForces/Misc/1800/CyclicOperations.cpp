//
// Created by JMKov on 4/22/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int n, k;
int ln[100004];
int arr[100004];

void findCycle(int a) {
    vector<int> tr;
    tr.push_back(a);
    int b = arr[a];
    while (a != b && !ln[a] && !ln[b]) {
        tr.push_back(a);
        tr.push_back(b);
        a = arr[a];
        b = arr[arr[b]];
    }
    if (ln[a] || ln[b]) {
        ln[a] = max(ln[a], ln[b]);
        ln[b] = ln[a];
        for (int i : tr) ln[i] = ln[a];
        return;
    }
    tr.push_back(a);
    a = arr[a];
    int cnt = 1;
    while (a != b) {
        tr.push_back(a);
        a = arr[a];
        cnt++;
    }
    for (int i : tr) ln[i] = cnt;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    if (k == 1) {
        for (int i = 0; i < n; i++) if (arr[i] != i) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!ln[i]) findCycle(i);
    }
    for (int i = 0; i < n; i++) {
        if (ln[i] != k) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        for (int i = 0; i < n; i++) {
            ln[i] = 0;
        }
    }
    return 0;
}