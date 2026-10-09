//
// Created by JMKov on 6/4/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> points[k];
    string s;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }
    else if (n == 1) {
        for (int i = 0; i < m - 1; i++) s += 'R';
        for (int i = 0; i < m - 1; i++) s += 'L';
    }
    else if (m == 1) {
        for (int i = 0; i < n - 1; i++) s += 'D';
        for (int i = 0; i < n - 1; i++) s += 'U';
    }
    else {
        for (int i = 0; i < n - 1; i++) s += 'D';
        for (int i = 0; i < m - 1; i++) s += 'R';
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = 0; j < m - 1; j++) s += 'R';
            }
            else {
                for (int j = 0; j < m - 1; j++) s += 'L';
            }
            if (i != n - 1) s += 'U';
        }
    }
    cout << s.size() << endl;
    cout << s << endl;
    return 0;
}