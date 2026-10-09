//
// Created by JMKov on 4/12/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ent[n];
    int exi[n];
    bool checked[n + 1];
    int ord[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> ent[i];
        checked[i] = false;
    }
    checked[n] = false;
    for (int i = 0; i < n; i++) {
        cin >> exi[i];
        ord[exi[i]] = i;
    }
//    for (int i = 0; i < n; i++) {
//        cout << ent[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < n; i++) {
//        cout << exi[i] << " ";
//    }
//    cout << endl;
    int ans = 0;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        int val = exi[i];
        checked[val] = true;
        if (ent[ptr] != val) {
//            cout << i << " " << ptr << " " << ent[ptr] << " " << exi[i] << endl;
            ans++;
        }
        else {
//            cout << i << " " << ptr << " " << ent[ptr] << " " << exi[i] << endl;
            while (checked[ent[ptr]]) {
//                cout << ent[ptr] << endl;
                ptr++;
                if (ptr >= n) {
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}