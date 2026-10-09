//
// Created by JMKov on 7/2/2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int decomp[1000];
int pre[100010];

int sum(int l, int r, int length) {
    int sum = 0;
    int c_l = l / length;
    int c_r = r / length;
    if (c_r - c_l <= 1) {
        for (int i = l; i <= r; i++) {
            sum += pre[i];
        }
    }
    else {
        for (int i = l; i < (c_l + 1) * length; i++) {
            sum += pre[i];
        }
        for (int i = c_l + 1; i <= c_r - 1; i++) {
            sum += decomp[i];
        }
        for (int i = c_r * length; i <= r; i++) {
            sum += pre[i];
        }
    }
    return sum;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, m;
    cin >> n >> m;
    int arr[n];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<pair<int, int>> queries[n];

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[r].insert(*new pair<int, int>(l, i));
    }
    int len = ceil(sqrt(n));
    int ans[m];
    for (int i = 0; i < n; i++) {
        pre[i] = 0;
        mp[arr[i]].push_back(i);
        if (mp[arr[i]].size() >= arr[i]) {
            int index = mp[arr[i]][mp[arr[i]].size() - arr[i]];
            pre[index]++;
            decomp[index / len]++;
        }
        if (mp[arr[i]].size() > arr[i]) {
            int index = mp[arr[i]][mp[arr[i]].size() - arr[i] - 1];
            pre[index] -= 2;
            decomp[index / len] -= 2;
        }
        if (mp[arr[i]].size() > arr[i] + 1) {
            int index = mp[arr[i]][mp[arr[i]].size() - arr[i] - 2];
            pre[index]++;
            decomp[index / len]++;
        }
        for (pair<int, int> j : queries[i]) {
            ans[j.second] = sum(j.first, i, len);
        }
//        for (int j : pre) cout << j << " ";
//        cout << endl;
    }
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
//8 7
//3 1 2 2 3 2 3 2
//1 3
//1 5
//1 6
//3 4
//3 6
//4 6
//1 8
//ans: 1 2 1 1 0 1 2


//0 1 0 0 0 0 0
//0 0-1 1 0 0 0
//0 0 0 0 0 0 0
//0 0 0 0 0 0 0
//0 0 0 0 0 0 0
