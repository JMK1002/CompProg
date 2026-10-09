//
// Created by JMKov on 4/26/2023.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    int xCount[n];
    int yCount[m];
    int walls = 0;
    for (int i = 0; i < n; i++) {
        xCount[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        yCount[j] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '*') {
                xCount[i]++;
                yCount[j]++;
                walls++;
            }
        }
    }
    int highestX = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (highestX < xCount[i]) {
            highestX = xCount[i];
            a.erase(a.begin(), a.end());
        }
        if (highestX == xCount[i]) {
            a.insert(a.begin(), i);
        }
    }
    int highestY = 0;
    vector<int> b;
    for (int i = 0; i < m; i++) {
        if (highestY < yCount[i]) {
            highestY = yCount[i];
            b.erase(b.begin(), b.end());
        }
        if (highestY == yCount[i]) {
            b.insert(b.begin(), i);
        }
    }
    for (int x : a) {
        for (int y : b) {
//            cout << xCount[x] << " " << yCount[y] << " " << (arr[x][y] == '*') << x << " " << y << " " << endl;
            if (xCount[x] + yCount[y] < walls) {
                cout << "NO" << endl;
                return 0;
            }
            if (xCount[x] + yCount[y] - (arr[x][y] == '*') == walls) {
                cout << "YES" << endl;
                cout << x + 1 << " " << y + 1 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}