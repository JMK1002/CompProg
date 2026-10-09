//
// Created by JMKov on 12/28/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, c, m;
int queries[103][3];

int mnY(int x) {
    int ret = m; // maybe c idk
    for (int i = 0; i < n; i++) {
        ret = min(ret, (queries[i][2] - queries[i][0] * x) / queries[i][1]);
    }
    return ret;
}

int cost(int x, int y) {
    return (c - x) + (m - y);
}

void solve() {
    cin >> n >> c >> m;

    for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> queries[i][j];

    int low = 0;
    int high = c;
    while (low < high) {
        int mid = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {

    }
    return 0;
}