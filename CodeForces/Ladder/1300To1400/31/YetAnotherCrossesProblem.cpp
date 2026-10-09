//
// Created by JMKov on 4/11/2023.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int r, c;
        cin >> r >> c;
        string arr[r];
        for (int i = 0; i < r; i++) {
            cin >> arr[i];
        }
        // how many white cells there are
        int mnRow = c;
        int mnColumn = r;
        vector<int> a(0);
        vector<int> b(0);
        for (int i = 0; i < r; i++) {
            int count = 0;
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == '.') {
                    count++;
                }
            }
            if (count < mnRow) {
                a.erase(a.begin(), a.end());
                a.insert(a.end(), i);
                mnRow = count;
            }
            else if (count == mnRow) {
                a.insert(a.end(), i);
            }
        }
        for (int i = 0; i < c; i++) {
            int count = 0;
            for (int j = 0; j < r; j++) {
                if (arr[j][i] == '.') {
                    count++;
                }
            }
            if (count < mnColumn) {
                b.erase(b.begin(), b.end());
                b.insert(b.end(), i);
                mnColumn = count;
            }
            else if (count == mnColumn) {
                b.insert(b.end(), i);
            }
        }
        bool intersect = false;
        for (int i : a) {
            for (int j : b) {
                if (arr[i][j] == '.') {
                    intersect = true;
                    break;
                }
            }
            if (intersect) {
                break;
            }
        }
        cout << mnRow + mnColumn - intersect << endl;
    }
    return 0;
}