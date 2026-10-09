//
// Created by JMKov on 3/21/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> aCycle(2, b);
    vector<int> cCycle(2, d);
    aCycle[1] = (b + a);
    cCycle[1] = (d + c);
    while (b % c != aCycle[aCycle.size() - 1] % c) {
        aCycle.insert(aCycle.end(), (aCycle[aCycle.size() - 1] + a));
        //cout << aCycle[aCycle.size() - 1] << " ";
    }
    //cout << endl;
    while (d % a != cCycle[cCycle.size() - 1] % a) {
        cCycle.insert(cCycle.end(), (cCycle[cCycle.size() - 1] + c));
        //cout << cCycle[cCycle.size() - 1] << " ";
    }
    //cout << endl;
    int deltaC = cCycle[cCycle.size() - 1] - cCycle[0];
    for (int i : aCycle) {
        for (int j : cCycle) {
            if (i % deltaC == j % deltaC) {
                cout << max(i, j) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}