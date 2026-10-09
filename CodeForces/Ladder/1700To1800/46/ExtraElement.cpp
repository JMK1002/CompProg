//
// Created by JMKov on 6/25/2023.
//
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[200010];

bool compare(int a, int b) {
    return arr[a] < arr[b];
}

int solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    int indicies[n];
    for (int i = 0; i < n; i++) {
        indicies[i] = i;
        cin >> arr[i];
    }
    sort(indicies, indicies + n, compare);
    sort(arr, arr + n);
    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        mp[arr[i] - arr[i - 1]]++;
    }
    if (mp.size() > 3) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) mp[arr[i] - arr[i - 1]]--;
        if (i != n - 1) mp[arr[i + 1] - arr[i]]--;
        int v = -1;
        bool works = true;
        for (auto p : mp) {
            if (p.second != 0 && v == -1) {
                v = p.first;
            }
            else if (p.second != 0 && v != -1) {
                works = false;
                break;
            }
        }
//        cout << works << endl;
        works = works && (i == 0 || i == n - 1 || arr[i + 1] - arr[i - 1] == v) && v != -1;
        if (works) {
            cout << indicies[i] + 1 << endl;
            return 0;
        }
        if (i != 0) mp[arr[i] - arr[i - 1]]++;
        if (i != n - 1) mp[arr[i + 1] - arr[i]]++;
    }
    cout << -1 << endl;
    return 0;
}

int main() {
//    int t;
//    cin >> t;
//    while (t--) {
        solve();
//    }
}