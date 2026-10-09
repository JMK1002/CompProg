//
// Created by JMKov on 5/14/2023.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    int notUnique = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
        if (mp[arr[i]] == 2) {
            notUnique++;
        }
    }
    if (notUnique == 0) {
        cout << 0 << endl;
        return 0;
    }
    int mn = 1000000000;
    for (int i = 0; i < n; i++) {
        map<int, int> count = mp;
        int asdf = 0;
        for (int j = i; j < n; j++) {
            count[arr[j]]--;
            if (count[arr[j]] == 1) {
                asdf++;
            }
            if (asdf == notUnique) {
                mn = min(mn, j - i + 1);
                break;
            }
        }
    }
    cout << mn << endl;
}