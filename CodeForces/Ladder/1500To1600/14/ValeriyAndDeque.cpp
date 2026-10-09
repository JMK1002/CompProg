//
// Created by JMKov on 5/9/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int mx = -1;
    vector<int> arr(n);
    vector<pair<int, int>> steps;
    for (int i = 0; i < n; i++) {cin >> arr[i]; mx = max(mx, arr[i]);}
    while (arr[0] != mx) {
        steps.emplace_back(arr[0], arr[1]);
//        cout << arr[0] << " " << arr[1] << endl;
        int v = arr[arr[0] > arr[1]];
        arr.erase(arr.begin() + (arr[0] > arr[1]));
        arr.insert(arr.end(), v);
//        for (int i : arr) {
//            cout << i << " ";
//        }
//        cout << endl;
    }
    while (q--) {
        long long v;
        cin >> v;
        v--;
        if (v >= steps.size()) {
            v -= steps.size();
            cout << arr[0] << " " << arr[v % (arr.size() - 1) + 1] << endl;
        }
        else {
            cout << steps[v].first << " " << steps[v].second << endl;
        }
    }
    return 0;
}