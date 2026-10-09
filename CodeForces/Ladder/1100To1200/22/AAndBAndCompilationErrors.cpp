#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(3);
    for(int i = 0; i < 3; i++) {
        vector<int> b(n - i);
        a[i] = b; 
        for (int j = 0; j < n - i; j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; i++) {
        if (a[0][i] != a[1][i]) {
            cout << a[0][i] << endl;
            i = n;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[1][i] != a[2][i]) {
            cout << a[1][i] << endl;
            i = n;
        }
    }
    return 0;
}