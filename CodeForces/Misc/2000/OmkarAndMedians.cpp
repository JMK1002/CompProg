//
// Created by JMKov on 6/17/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n;
int arr[200004];
set<int> run;

void clean() {
    for (int i = 0; i < n; i++) arr[i] = 0;
    run.clear();
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    run.insert(arr[0]);
    for (int i = 1; i < n; i++) {
        run.insert(arr[i]);
//        cout << distance(run.find(arr[i - 1]), run.find(arr[i])) << endl;
        if (distance(run.find(min(arr[i - 1], arr[i])), run.find(max(arr[i - 1], arr[i]))) >= 2) {
            cout << "NO" << endl;
            clean();
            return;
        }
    }
    cout << "YES" << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//wtf250