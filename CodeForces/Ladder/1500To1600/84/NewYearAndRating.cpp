//
// Created by JMKov on 6/1/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int val[n];
    int div[n];
    cin >> val[0] >> div[0];
    int low; int high;
    if (div[0] == 2) {
        high = 1899 + val[0];
        low = -1000000000 + val[0];
    }
    else {
        low = 1900 + val[0];
        high = 1000000000 + val[0];
    }
    for (int i = 1; i < n; i++) {
        cin >> val[i] >> div[i];
        if ((div[i] == 1 && high < 1900) || (div[i] == 2 && low > 1899)) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (div[i] == 1) {
            low = max(low, 1900);
        }
        else {
            high = min(high, 1899);
        }
        low += val[i]; high += val[i];
    }
    if (high > 400000000) {
        cout << "Infinity" << endl;
        return 0;
    }
    cout << high << endl;
    return 0;
}
//3
//-7 1
//5 2
//8 2