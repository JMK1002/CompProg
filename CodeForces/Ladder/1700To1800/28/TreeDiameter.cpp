//
// Created by JMKov on 6/16/2023.
//
#include <iostream>
#include <vector>
using namespace std;

bool query(int n, int m) {
    vector<int> a;
    vector<int> b;
    bool vector = true;
    for (int i = 0; i < n; i++) {
        if (i % m == 0) vector = !vector;
        if (vector) {
            a.push_back(i + 1);
        }
        else {
            b.push_back(i + 1);
        }
    }
    if (a.size() == 0 || b.size() == 0) return false;
    cout << a.size() << " ";
    cout << b.size() << " ";
    for (int i : a) cout << i << " ";
    for (int i : b) cout << i << " ";
    cout << endl;
    cout.flush();
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 9; i++) {
            if (!query(n, 1 << i)) {
                break;
            }
            int v;
            cin >> v;
            ans = max(ans, v);
        }
        cout << -1 << " " << ans << endl;
    }
    return 0;
}