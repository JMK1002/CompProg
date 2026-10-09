//
// Created by JMKov on 4/22/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, long long> a;
    map<int, bool> exists;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (!exists[v - i]) {
            exists[v - i] = true;
            a[v - i] = 0;
        }
        a[v - i] += v;
        mx = max(a[v - i], mx);
    }
    cout << mx << endl;
    return 0;
}