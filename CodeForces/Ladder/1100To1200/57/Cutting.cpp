//
// Created by JMKov on 3/25/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    int seq[n];
    int balanceCount[n];

    cin >> seq[0];
    balanceCount[0] = (seq[0] % 2 == 1 ? 1 : -1);
    for (int i = 1; i < n; i++) {
        cin >> seq[i];
        balanceCount[i] = balanceCount[i - 1] + (seq[i] % 2 == 1 ? 1 : -1);
    }
    vector<int> cutCosts(0);
    for (int i = 0; i < n - 1; i++) {
        if (balanceCount[i] == 0) {
            cutCosts.insert(cutCosts.end(), abs(seq[i] - seq[i + 1]));
            //cout << cutCosts[cutCosts.size() - 1] << " ";
        }
    }
    //cout << endl;
    sort(cutCosts.begin(), cutCosts.end());
    int cost = 0;
    for (int i = 0; i < cutCosts.size(); i++) {
        if (cost + cutCosts[i] > b) {
            cout << i << endl;
            return 0;
        }
        cost += cutCosts[i];
    }
    cout << cutCosts.size() << endl;
    return 0;
}