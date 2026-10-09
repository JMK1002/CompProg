#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void dfs(int a, int* positions, int* sups) {
    if (positions[a] != -1) {
        return;
    }
    else if (sups[a] == -1) {
        positions[a] = 0;
    }
    else if (positions[sups[a] - 1] == -1) {
        dfs(sups[a] - 1, positions, sups);
        dfs(a, positions, sups);
    }
    else {
        positions[a] = positions[sups[a] - 1] + 1;
    }
}

int main() {
    int n;
    cin >> n;
    int positions[n];
    int* pPos = positions;
    int sups[n];
    int* pSups = sups;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> sups[i];
        positions[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        dfs(i, pPos, pSups);
    }

    for (int i : positions) {
        mx = max(mx, i);
    }
    cout << mx + 1 << endl;
    return 0;
}