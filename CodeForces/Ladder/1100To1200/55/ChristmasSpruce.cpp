//
// Created by JMKov on 3/24/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tree[n]; // input
    int leafCount[n]; // leaf count
    bool isLeaf[n]; // is a leaf
    for (int i = 0; i < n; i++) {
        isLeaf[i] = true;
        tree[i] = 0;
        leafCount[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> tree[i];
        tree[i]--;
        isLeaf[tree[i]] = false;
    }
    for (int i = 0; i < n; i++) {
        leafCount[tree[i]] += isLeaf[i];
//        cout << tree[i] << isLeaf[i] << endl;
    }
    for (int i = 0; i < n; i++) {
//        cout << leafCount[i] << endl;
        if (leafCount[i] < 3 && !isLeaf[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}