//
// Created by JMKov on 6/24/2023.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> s >> n;
        string arr[n];
        int dp[s.size()];
        vector<pair<int, int>> pain[s.size()];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < s.size(); i++) dp[i] = -1;
        for (int i = 0; i < s.size(); i++) {
            for (int x = 0; x < n; x++) {
                const string & str = arr[x];
                if (str.size() > i + 1) continue;
//                cout << i << " " << str << endl;
                bool work = true;
                int mn = 2000000000;
                int index = 0;
                for (int j = 0; j < str.size() && work; j++) {
                    if (str[j] != s[j + i - str.size() + 1]) {
                        work = false;
                    }
//                    if (j + i - str.size() >= s.size()) cout << i << " " << j << " " << str << " " << j + i - (int) str.size() << endl;
                    if (j + i - (int) str.size() >= 0 && j + i - (int) str.size() < (int) s.size()) {
                        if (dp[j + i - (int) str.size()] != -1 && dp[j + i - (int) str.size()] < mn) {
                            mn = dp[j + i - (int) str.size()];
                            index = j + i - (int) str.size();
                        }
                    }
                }
                if (!work || mn >= 200000000 && str.size() != i + 1) continue;
                if (str.size() == i + 1) {
                    dp[i] = 1;
                    pain[i] = *new vector<pair<int, int>>(0);
                    pain[i].emplace_back(x, 0);
                }
                else {
                    dp[i] = mn + 1;
                    pain[i] = pain[index];
                    pain[i].emplace_back(x, i - str.size() + 1);
                }
            }
        }
//        for (int i : dp) cout << i << " ";
//        cout << endl;
        cout << dp[s.size() - 1] << endl;
        if (dp[s.size() - 1] == -1) continue;
        for (pair<int, int> p : pain[s.size() - 1]) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
    return 0;
}