//
// Created by JMKov on 8/5/2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, m, t;
set<pair<int, int>> goals[2]; // 0 for blue, 1 for red
pair<int, int> pos[2][10];
pair<int, int> bludger;
pair<int, int> snitch;
int score[2];

int main() {
    cin >> n >> m;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 10; j++) pos[i][j] = {-30000000, -30000000};
    bludger = {-30000000, -30000000};
    snitch = {-30000000, -30000000};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            if (s == ".Q" || s == "..") continue;
            if (s == ".B") {
                bludger = {i, j};
                continue;
            }
            if (s == ".S") {
                snitch = {i, j};
                continue;
            }
            bool b = (s[0] == 'R');
            if (s[1] == 'G') goals[b].insert({i, j});
            else {
                pos[b][s[1] - '0'] = {i, j};
            }
        }
    }
    map<char, pair<int, int>> dir;
    dir['U'] = {-1, 0};
    dir['L'] = {0, -1};
    dir['D'] = {1, 0};
    dir['R'] = {0, 1};
    int cnt = 0;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool b = (s[0] == 'R');
        int ind = s[1] - '0';
        char c;
        cin >> c;
        if (c == 'C') {
            string asdf;
            cin >> asdf;
            if (asdf == ".S") {
                score[b] += 10;
                cout << cnt << " " << (b ? "RED" : "BLUE") << " CATCH GOLDEN SNITCH" << endl;
            }
        }
        else if (c == 'T') {
            pair<int, int> p = pos[b][ind];
            if (goals[0].find(p) != goals[0].end()) {
                cout << cnt << " RED GOAL" << endl;
                score[1]++;
            }
            else if (goals[1].find(p) != goals[1].end()) {
                cout << cnt << " BLUE GOAL" << endl;
                score[0]++;
            }
        }
        else {
            if (s == ".B") {
                bludger.first += dir[c].first;
                bludger.second += dir[c].second;
                for (int i = 0; i < 2; i++) for (int j = 0; j < 10; j++) {
                    if (pos[i][j] == bludger) {
                        cout << cnt << " " << ((i) ? 'R' : 'B') << j << " ELIMINATED" << endl;
                        pos[i][j] = {-30000000, -30000000};
                    }
                }
            }
            else if (s != ".S" && s != ".Q") {
                pos[b][ind].first += dir[c].first;
                pos[b][ind].second += dir[c].second;
                if (pos[b][ind] == bludger) {
                    cout << cnt << " " << ((b) ? 'R' : 'B') << ind << " ELIMINATED" << endl;
                    pos[b][ind] = {-30000000, -30000000};
                }
            }
        }
        cnt++;
    }
    cout << "FINAL SCORE: " << score[1] << " " << score[0] << endl;
    return 0;
}