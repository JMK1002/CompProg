#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    int maxs[n];
    int tally[m] = { 0 };
    for (int i = 0; i < n; i++) {
        long long mx = -1;
        int index = -1;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a > mx) {
                mx = a;
                index = j;
            }
        }
        maxs[i] = index;
    }
    for (int i : maxs) {
        tally[i]++;
    }
    int index = -1;
    int max = -1;
    for (int i = 0; i < m; i++) {
        if (tally[i] > max) {
            max = tally[i];
            index = i;
        }
    }
    cout << index + 1 << endl;

    return 0;
}