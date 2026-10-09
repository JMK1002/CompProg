//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string s, c;
int arr[100004];

void solve() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    arr[m] = 10000000;
    cin >> c;
    sort(arr, arr + m);
    sort(c.begin(), c.end());
//    cout << c << endl; // checking if it works
    int front = 0;
    int back = m - 1;

    for (int i = 0; i < m; i++) {
        if (arr[i] == arr[i + 1]) {
            s[arr[i]] = c[back];
            back--;
        }
        else {
            s[arr[i]] = c[front];
            front++;
        }
    }
    cout << s << endl;
//    cout << front << " " << back << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}