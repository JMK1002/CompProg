//
// Created by JMKov on 2/24/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v = {1, 6, 9, 10};
    while (t--) {
        vector<pair<int, bool>> asdf;
        map<int, int> cnt;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            cnt[u]++;
            cnt[u + v]--;
        }
        int runCnt = 0;
        int mx = 0;
        for (pair<int, int> p : cnt) {
//            cout << p.first << " " << p.second << endl;
            runCnt += p.second;
            mx = max(runCnt, mx);
        }
        cout << mx << endl;
    }
    return 0;
}
//1
//5
//10 20
//40 50
//20 30
//50 60
//30 40