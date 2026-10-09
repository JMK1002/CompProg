//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <set>

using namespace std;

pair<int, int> dirs[4] {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};
char chars[4] = {'L', 'U', 'R', 'D'};
set<string> ans;
bool explored[7][7];
int lft;

void dfs(int x, int y, string s) {
    explored[x][y] = true;
    if (s.length() == 48 && x == 0 && y == 6) {
        ans.insert(s);
        return;
    }
    if (x == 0 && y == 6) {
        explored[x][y] = false;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i].first;
        int ny = y + dirs[i].second;
        if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7 || explored[nx][ny]) continue;
        dfs(nx, ny, s + chars[i]);
    }
    explored[x][y] = false;
}

int main() {
    string s;
    cin >> s;
    dfs(0, 0, "");
    int fin = 0;
    for (string a : ans) {
        bool worked = true;
        for (int i = 0; i < 48; i++) {
            if (s[i] != '?' && a[i] != s[i]) {
                worked = false;
                break;
            }
        }
        fin += worked;
    }
    cout << fin << endl;
    return 0;
}