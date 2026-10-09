#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int houses[n];
    int luxDist[n];
    int max = -1;
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (houses[i] > max) {
            max = houses[i];
            luxDist[i] = max - houses[i];
        }
        else {
            luxDist[i] = max - houses[i] + 1;
        }
    }
    for (int i : luxDist) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}