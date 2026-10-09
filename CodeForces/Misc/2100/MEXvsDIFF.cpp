//
// Created by JMKov on 7/21/2024.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
int arr[100005];
bool exists[100005];
map<int, int> mp;
vector<pair<int, int>> ord;
vector<int> flatOrd;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 100005) exists[arr[i]] = true;
        mp[arr[i]]++;
    }
    int mxMex = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (exists[i]) {
            mxMex++;
            continue;
        }
        cnt++;
        if (cnt > k) break;
        mxMex++;
    }
    for (pair<int, int> p : mp) {
        if (p.first < mxMex) continue;
        ord.push_back({p.second, p.first});
    }
    sort(ord.begin(), ord.end());
    for (pair<int, int> p : mp) {
        if (p.first < mxMex) {
            ord.push_back({p.second - 1, p.first});
        }
    }
    for (int i = 0; i < ord.size(); i++) {
        for (int j = 0; j < ord[i].first; j++) flatOrd.push_back(ord[i].second);
    }
    flatOrd.push_back(239487680);
    int ans = mp.size();
    int mex = 0;
    while (exists[mex]) {
        mex++;
        ans--;
    }
    int actAns = ans;
    int x = flatOrd.size();
    for (int i = 1; i <= min(x - 1, k); i++) {
        ans += (flatOrd[i - 1] == flatOrd[i] || flatOrd[i - 1] < mxMex);
        mex++;
        ans--;
        while (exists[mex] && mex < mxMex) {
            mex++;
            ans--;
        }
        actAns = min(actAns, ans);
    }
    cout << actAns << endl;
    mp.clear();
    ord.clear();
    flatOrd.clear();
    for (int i = 0; i <= n; i++) {
        if (arr[i] < 100005) exists[arr[i]] = false;
        arr[i] = 0;
        exists[i] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}