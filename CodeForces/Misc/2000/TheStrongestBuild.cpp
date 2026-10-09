//
// Created by JMKov on 6/17/2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n;
vector<int> arr[10];
set<vector<int>> blocked;
map<vector<int>, bool> mp;
int tot = 1;
vector<int> curr;
int ans = 0;
vector<int> res;

void dfs() {
    mp[curr] = true;
    if (blocked.end() != blocked.find(curr)) {
        for (int i = 0; i < n; i++) {
            if (curr[i] == arr[i].size() - 1) continue;
            curr[i]++;
            if (!mp[curr]) dfs();
            curr[i]--;
        }
    }
    else {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i][curr[i]];
        }
        if (sum > ans) {
            ans = sum;
            res = curr;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
        reverse(arr[i].begin(), arr[i].end());
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        vector<int> block;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            block.push_back(arr[j].size() - x);
        }
        blocked.insert(block);
    }
    for (int i = 0; i < n; i++) curr.push_back(0);
    dfs();
//    cout << ans << endl;
//    for (int i = 0; i < n; i++) cout << lens[i] << " ";
//    cout << endl;
    for (int i = 0; i < n; i++) cout << arr[i].size() - res[i] << " ";
    cout << endl;
    return 0;
}