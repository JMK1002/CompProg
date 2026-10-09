//
// Created by JMKov on 6/24/2023.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int costs[n];
    int arr[n];
    set<int> asdf[n];
    for (int i = 0; i < n; i++) cin >> costs[i];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        asdf[arr[i]].insert(i);
    }
    int explored[n];
    int ans = 0;
    for (int j = 0; j < n; j++) explored[j] = 0;
    for (int i = 0; i < n; i++) {
        if (explored[i] != 0) continue;
//        cout << i << " " << ans << endl;
        vector<int> path;
        path.push_back(i);
        explored[i] = 1;
        while (explored[arr[path[path.size() - 1]]] == 0) {
            explored[arr[path[path.size() - 1]]] = 1;
            path.push_back(arr[path[path.size() - 1]]);
        }
        if (explored[arr[path[path.size() - 1]]] == 2) {
            for (int j = 0; j < path.size(); j++) {
                explored[path[j]] = 2;
            }
//            for (int i : explored) cout << i << " ";
//            cout << endl;
            continue;
//            cout << path[path.size() - 1] << "SDF" << endl;
        };
//        cout << path[path.size() - 1] << endl;
        int mn = INT32_MAX;
        bool inLoop = true;
        for (int j = path.size() - 1; j >= 0; j--) {
            if (inLoop) {
                mn = min(mn, costs[path[j]]);
            }
            if (inLoop && path[j] == arr[path[path.size() - 1]]) {
                inLoop = false;
            }
            explored[path[j]] = 2;
        }
        ans += mn;
//        for (int i : explored) cout << i << " ";
//        cout << endl;
    }

    cout << ans << endl;
    return 0;
}