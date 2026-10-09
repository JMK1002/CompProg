#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int hs[n];
    int ps[n];
    cin >> hs[0];
    ps[0] = hs[0];
    for (int i = 1; i < n; i++) {
        cin >> hs[i];
        ps[i] = ps[i - 1] + hs[i];
    }
    int mn = ps[k - 1];
    int index = 1;

    for (int i = 1; i < n - k + 1; i++) {
        if (ps[i + k - 1] - ps[i - 1] < mn) {
            index = i + 1;
            mn = ps[i + k - 1] - ps[i - 1];
        }
    }
    cout << index << endl;
    return 0;
}