//
// Created by JMKov on 4/19/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<long long, bool> uniqueExists;
    map<long long, int> uniqueCount;
    vector<long long> uniqueVals;
    map<int, bool> existsX;
    map<int, bool> existsY;
    map<int, int> countX;
    map<int, int> countY;
    vector<int> xVals;
    vector<int> yVals;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        long long id = x * (long long) INT32_MAX + y;
        if (!uniqueExists[id]) {
            uniqueCount[id] = 0;
            uniqueVals.insert(uniqueVals.end(), id);
            uniqueExists[id] = true;
        }
        uniqueCount[id]++;
//        cout << uniqueCount[id] << " " << id << endl;
        if (!existsX[x]) {
            countX[x] = 0;
            existsX[x] = true;
            xVals.insert(xVals.end(), x);
        }
        countX[x]++;

        if (!existsY[y]) {
            countY[y] = 0;
            existsY[y] = true;
            yVals.insert(yVals.end(), y);
        }
        countY[y]++;
    }
    long long ans = 0;
    for (int i : xVals) {
//        cout << (long long) countX[i] * (countX[i] - 1) / 2 << endl;
        ans += (long long) countX[i] * (countX[i] - 1) / 2;
    }
    for (int i : yVals) {
//        cout << (long long) countY[i] * (countY[i] - 1) / 2 << endl;
        ans += (long long) countY[i] * (countY[i] - 1) / 2;
    }
    for (long long i : uniqueVals) {
//        cout << uniqueCount[i] << endl;
//        cout << (long long) uniqueCount[i] * (uniqueCount[i] - 1) / 2 << endl;
        ans -= (long long) uniqueCount[i] * (uniqueCount[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}