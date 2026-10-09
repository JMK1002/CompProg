//
// Created by JMKov on 6/23/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    bool a = false;
    bool b = false;
    map<int, bool> mp;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (mp[arr[i] - x]) {
            b = true;
        }
        if (mp[arr[i] - y]) {
            a = true;
        }
    }
    if (a && b) cout << 0 << endl;
    else if (a && !b) cout << 1 << endl << x << endl;
    else if (!a && b) cout << 1 << endl << y << endl;
    else {
        bool worked = false;
        for (int i = 0; i < n; i++) {
            if (mp[arr[i] - (y - x)] && arr[i] + x < l) {
                cout << 1 << endl << arr[i] + x << endl;
                worked = true;
                break;
            }
            else if (mp[arr[i] - (y - x)] && arr[i] - y > 0) {
                cout << 1 << endl << arr[i] - y << endl;
                worked = true;
                break;
            }
//            cout << arr[i] << "SDF" << endl;
        }
        if (worked) return 0;
        for (int i = 0; i < n; i++) {
            if (mp[arr[i] - (x + y)]) {
                cout << 1 << endl << arr[i] - x << endl;
                worked = true;
                break;
            }
//            cout << arr[i] << "SDF" << endl;
        }
        if (worked) return 0;
        cout << 2 << endl << x << " " << y << endl;
    }
    return 0;
}