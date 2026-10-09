//
// Created by JMKov on 5/28/2024.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k;
bool arr[102][32][32];
pair<int, int> ord[102];
vector<pair<int, pair<int, int>>> ans;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a > b;
}

void col(int a, int b) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (arr[a][i][j] != arr[b][i][j]) {
                ans.push_back({1, {i + 1, j + 1}});
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            for (int l = 0; l < m; l++) {
                arr[i][j][l] = s[l] - '0';
            }
        }
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int l = 1; l < m - 1; l++) {
                bool t = arr[i][j][l];
                cnt += (arr[i][j + 1][l] != t && arr[i][j][l + 1] != t &&
                    arr[i][j - 1][l] != t && arr[i][j][l - 1] != t);
            }
        }
        ord[i].first = cnt;
        ord[i].second = i;
    }

    sort(ord, ord + k + 1, comp);

//    for (int i = 0; i <= k; i++) cout << ord[i].first << " " << ord[i].second << endl;

    for (int i = 0; i < k; i++) {
        if (ord[i].first == ord[i + 1].first) {
            ans.push_back({2, {ord[i + 1].second + 1, -1}});
        }
        else {
            col(ord[i].second, ord[i + 1].second);
            ans.push_back({2, {ord[i + 1].second + 1, -1}});
        }
    }
    cout << ord[0].second + 1 << endl;
    cout << ans.size() << endl;
    for (pair<int, pair<int, int>> p : ans) {
        if (p.first == 1) cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        else cout << p.first << " " << p.second.first << endl;
    }
    return 0;
}