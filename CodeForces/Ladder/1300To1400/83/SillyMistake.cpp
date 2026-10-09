//
// Created by JMKov on 4/29/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    vector<int> out(1, -1);
    map<int, int> entrances;
    map<int, bool> inBuilding;
    int inBuildingCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int a = arr[i];
        if (a > 0) {
            if (inBuilding[a]) {
                cout << -1 << endl;
                return 0;
            }
            entrances[a]++;
            inBuildingCount++;
            inBuilding[a] = true;
        }
        else {
            if (!inBuilding[abs(a)]) {
                cout << -1 << endl;
                return 0;
            }
            inBuildingCount--;
            inBuilding[abs(a)] = false;
        }
        if (entrances[a] > 1) {
            cout << -1 << endl;
            return 0;
        }
        if (inBuildingCount == 0) {
            out.push_back(i);
            map<int, int> asdf;
            entrances = asdf;
        }
    }
    if (inBuildingCount != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << out.size() - 1 << endl;
    for (int i = 1; i < out.size(); i++) {
//        cout << out[i] << endl;
        cout << out[i] - out[i - 1] << " ";
    }
    return 0;
}