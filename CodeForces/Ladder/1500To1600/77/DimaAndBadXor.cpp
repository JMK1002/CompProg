//
// Created by JMKov on 5/29/2023.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> check(int** matrix, int bit, int n, int m) {
    int one = 0;
    int zero = 0;
    int both = 0;
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        bool a = false;
        bool b = false;
        for (int j = 0; j < m; j++) {
            if ((matrix[i][j] >> bit) & 1) {
                a = true;
            }
            else {
                b = true;
            }
        }
        if (a && b) {
            both++;
            ret.push_back(-1);
        }
        else if (a) {
            one++;
            ret.push_back(0);
        }
        else {
            zero++;
            ret.push_back(0);
        }
    }
    if ((one & 1) == 0 && both >= 1) {
        bool got = false;
        for (int i = 0; i < n; i++) {
            if (ret[i] == -1) {
                int index = 0;
                if (!got) {
                    got = true;
                    while (!((matrix[i][index] >> bit) & 1)) index++;
                }
                else {
                    while (((matrix[i][index] >> bit) & 1)) index++;
                }
                ret[i] = index;
            }
        }
    }
    else if ((one & 1) == 1) {
        for (int i = 0; i < n; i++) {
            if (ret[i] == -1) {
                int index = 0;
                while (((matrix[i][index] >> bit) & 1)) index++;
                ret[i] = index;
            }
        }
    }
    else {
        return vector<int>(0);
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    int** matrix;
    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        vector<int> v = check(matrix, i, n, m);
        if (!v.empty()) {
            cout << "TAK" << endl;
            for (int j : v) cout << j + 1 << " ";
            return 0;
        }
    }
    cout << "NIE" << endl;
    return 0;
}
//5 5
//0 0 0 1 0
//1 1 1 1 1
//0 1 1 1 1
//1 1 1 0 0
//1 0 1 1 1