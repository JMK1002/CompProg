//
// Created by JMKov on 6/9/2024.
//
#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool works = false;
    int ind = -1;
    for (int i = 1; i < n; i++) if (arr[i] != arr[0]) {
        works = true;
        ind = i;
    }

    if (!works) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << "R";
    bool taken = false;
    for (int i = 1; i < n; i++) {
        if (!taken && ind != i) {
            taken = true;
            cout << "B";
        }
        else cout << "R";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}