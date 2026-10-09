//
// Created by JMKov on 7/6/2023.
//
#include <iostream>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    int * tree[n];
    tree[0] = new int[n];
    for (int i = 0; i < n; i++) cin >> tree[0][i];
    for (int i = 1; i < n; i++) {
        tree[i] = new int[n - i];
        for (int j = 0; j < n - i; j++) {
            tree[i][j] = (tree[i - 1][j] ^ tree[i - 1][j + 1]);
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i; j++) cout << tree[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            tree[i][j] = max(tree[i][j], max(tree[i - 1][j], tree[i - 1][j + 1]));
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i; j++) cout << tree[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << tree[r - l][l] << endl;
    }
    return 0;
}