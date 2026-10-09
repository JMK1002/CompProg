//
// Created by JMKov on 6/10/2023.
//
#include <iostream>
using namespace std;

bool better(int i, int j, const long long a[]) {
    long long v = a[i];
    long long ve = a[j];
    for (int k = 0; k < 60; k++) {
        if ((v & 1) && !(ve & 1)) {
            return true;
        }
        if (v == 0 && ve == 0) return false;
        v = v >> 1;
        ve = ve >> 1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    long long a[n];
    int b[n];
    int delusionalness[n];
    bool matrix[n][n];
    bool inGroup[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) delusionalness[i] = 0;
    for (int i = 0; i < n; i++) inGroup[i] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = better(i, j, a);
            delusionalness[i] += matrix[i][j];
        }
    }
    int v = n - 1;
    bool run = true;
    while (run) {
        run = false;
//        for (int i : delusionalness) cout << i << " ";
//        cout << endl;
        for (int i = 0; i < n; i++) {
            if (delusionalness[i] == v) {
                inGroup[i] = false;
                run = true;
                for (int j = 0; j < n; j++) {
                    delusionalness[j] -= matrix[j][i];
                }
                break;
            }
        }
        v--;
    }
    long long ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        ans += b[i] * inGroup[i];
//        cout << inGroup[i] << " ";
        count += inGroup[i];
    }
//    cout << endl;
    if (count < 2) {
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}