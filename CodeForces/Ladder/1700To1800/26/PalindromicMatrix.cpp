//
// Created by JMKov on 6/15/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n * n; i++) {
        int v;
        cin >> v;
        mp[v]++;
    }
    int matrix[n - n / 2][n - n / 2];
    int ptr = 0;
    if (n & 1) {
        int one = 0;
        int two = 0;
        for (pair<int, int> a : mp) {
            for (int i = 0; i < a.second / 4; i++) {
                if (ptr >= (n / 2) * (n / 2)) {
                    for (int j = 0; j < 2; j++) {
                        if (two == n - 1) {
                            cout << "NO" << endl;
                            return 0;
                        }
                        if (two >= n / 2) {
                            matrix[n / 2][two - n / 2] = a.first;
                        } else {
                            matrix[two][n / 2] = a.first;
                        }
                        two++;
                    }
                }
                matrix[ptr / (n / 2)][ptr % (n / 2)] = a.first;
                ptr++;
            }

            switch (a.second % 4) {
                case 1:
                    matrix[n / 2][n / 2] = a.first;
                    one++;
                    break;
                case 2:
                    if (two == n - 1) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    if (two >= n / 2) {
                        matrix[n / 2][two - n / 2] = a.first;
                    } else {
                        matrix[two][n / 2] = a.first;
                    }
                    two++;
                    break;
                case 3:
                    if (two == n - 1) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    if (two >= n / 2) {
                        matrix[n / 2][two - n / 2] = a.first;
                    } else {
                        matrix[two][n / 2] = a.first;
                    }
                    two++;
                    matrix[n / 2][n / 2] = a.first;
                    one++;
                    break;
            }
        }
        if (one != 1 || two != n - 1) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for (int i = 0; i <= n / 2; i++) {
            for (int j = 0; j <= n / 2; j++) {
                cout << matrix[i][j] << " ";
            }
            for (int j = n / 2 - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = n / 2 - 1; i >= 0; i--) {
            for (int j = 0; j <= n / 2; j++) {
                cout << matrix[i][j] << " ";
            }
            for (int j = n / 2 - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        for (pair<int, int> a : mp) {
            if (a.second % 4 != 0) {
                cout << "NO" << endl;
                return 0;
            }
            for (int i = 0; i < a.second / 4; i++) {
                matrix[ptr / (n / 2)][ptr % (n / 2)] = a.first;
                ptr++;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                cout << matrix[i][j] << " ";
            }
            for (int j = n / 2 - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = n / 2 - 1; i >= 0; i--) {
            for (int j = 0; j < n / 2; j++) {
                cout << matrix[i][j] << " ";
            }
            for (int j = n / 2 - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}