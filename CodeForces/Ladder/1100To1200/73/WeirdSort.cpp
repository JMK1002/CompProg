//
// Created by JMKov on 3/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int p[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        bool sortable = true;
        while (sortable) {
            sortable = false;
            for (int i = 0; i < m; i++) {
                if (a[p[i] - 1] > a[p[i]]) {
                    int b = a[p[i] - 1];
                    a[p[i] - 1] = a[p[i]];
                    a[p[i]] = b;
                    sortable = true;
                }
            }
        }
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                sorted = false;
                break;
            }
        }
        cout << (sorted ? "YES" : "NO") << endl;
    }
    return 0;
}