#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    int minCost = 100000000;
    int index = -1;
    for (int i = 0; i < 100; i++) {
        int cost = 0;
        for (int j = 0; j < n; j++) {
            cost += max(0, abs(list[j] - i) - 1);
        }
        if (cost <= minCost) {
            index = i;
            minCost = cost;
        }
    }
    cout << index << " " << minCost << endl;
    return 0;
}