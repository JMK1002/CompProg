//
// Created by JMKov on 12/14/2023.
//
#include <iostream>
using namespace std;
int fen[1000];
int arr[1000];

int query(int v, int len) {
    if ((v & -v) == 1) return fen[v];
    return min(fen[v - (v & -v)], arr[v - 1]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        int mx = arr[i];
        int mn = arr[i];
        for (int j = i; j < n; j++) {
            mx = max(arr[j], mx);
            mn = min(arr[j], mn);
            cout << mx - mn << " ";
        }
        cout << endl;
    }

//    fen[1] = arr[0];
//    for (int i = 1; i < n; i++) {
//        fen[i + 1] = min()
//    }
    return 0;
}
//2 8 5 1 10 5 9 9 3 5

//0 6 6 7 9 9 9 9 9 9
//0 3 7 9 9 9 9 9 9
//0 4 9 9 9 9 9 9
//0 9 9 9 9 9 9
//0 5 5 5 7 7
//0 4 4 6 6
//0 0 6 6
//0 6 6
//0 2
//0