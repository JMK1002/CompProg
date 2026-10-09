//
// Created by JMKov on 6/9/2023.
//
#include <iostream>
#include <set>
using namespace std;

long long update(int ** input, const multiset<int>& rows, int r) {
    long long s = 0;
    for (int i : rows) {
        for (int j : rows) {
            input[r][j] = min(input[r][j], input[r][i] + input[i][j]);
            input[j][r] = min(input[j][r], input[j][i] + input[i][r]);
//            input[i][j] = min(input[i][j], input[i][r] + input[r][j]);
            input[j][i] = min(input[j][i], input[j][r] + input[r][i]);
        }
    }
    for (int i : rows) for (int j : rows) s += input[j][i];
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < n; i++) {
//            cout << input[j][i] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    return s;
}

int main() {
    int n;
    cin >> n;
    int ** input;
    input = new int * [n];
    for (int i = 0; i < n; i++) {
        input[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    int order[n];
    multiset<int> rows;
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }
    long long out[n];
    for (int i = n - 1; i >= 0; i--) {
        rows.insert(order[i]);
        long long v = update(input, rows, order[i]);
        v = update(input, rows, order[i]);
        out[i] = v;
    }
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < n; i++) {
//            cout << input[j][i] << " ";
//        }
//        cout << endl;
//    }
    for (long long i : out) cout << i << " ";
    cout << endl;
    return 0;
}
//3
//0 2 4
//1 0 100
//2 1 0
//1 3 2

//4
//0 1 100 100
//100 0 100 1
//100 100 0 100
//100 100 1 0
// 1 2 3 4

//4
//0   1
//  0 400
//2 4 0 1
//    1 0