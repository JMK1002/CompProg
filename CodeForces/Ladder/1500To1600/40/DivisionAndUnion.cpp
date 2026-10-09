//
// Created by JMKov on 5/17/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> input;
        int ans[n];
        set<int> current;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            input.push_back(*new pair<int, int>(l, (i + 1)));
            input.push_back(*new pair<int, int>(r, (i + 1) * -1));
        }
        sort(input.begin(), input.end(), compare);
        bool type = false;
        int last = -1;
//        for (auto p : input) {
//            cout << p.first << " " << p.second << endl;
//        }
        for (auto p : input) {
            if (p.second < 0) {
                current.erase(current.find(p.second * -1));
                ans[p.second * -1 - 1] = type + 1;
            }
            else {
                if (last != p.first && current.empty()) {
                    type = !type;
                }
                current.insert(p.second);
            }
            last = p.first;
        }
        bool valid = false;
        for (int i : ans)  {
            if (i == 1) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}