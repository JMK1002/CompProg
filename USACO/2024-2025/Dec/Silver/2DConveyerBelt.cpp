#include <iostream>
#include <vector>
using namespace std;

int n, q;
int arr[1002][1002];
bool reachable[1002][1002];
vector<pair<pair<int, int>, int>> queries;
int cnt = 0;
int ans[200005];
vector<pair<int, int>> dirs = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

void dfs(pair<int, int> pos) {
    if (pos.first == -1 || pos.first == n || pos.second == -1 || pos.second == n || reachable[pos.first][pos.second]) return;

    if (arr[pos.first][pos.second] == -1) {
        for (pair<int, int> dir : dirs) {
            if (pos.first + dir.first == n || pos.first + dir.first == -1 || pos.second + dir.second == n || pos.second + dir.second == -1) {
                reachable[pos.first][pos.second] = true;
            }
            else {
                reachable[pos.first][pos.second] |= reachable[pos.first + dir.first][pos.second + dir.second];
            }
        }
    }
    else {
        pair<int, int> dir;

        dir = dirs[arr[pos.first][pos.second]];

        if (pos.first + dir.first == n || pos.first + dir.first == -1 || pos.second + dir.second == n || pos.second + dir.second == -1) {
            reachable[pos.first][pos.second] = true;
        }
        else {
            reachable[pos.first][pos.second] |= reachable[pos.first + dir.first][pos.second + dir.second];
        }
    }


    if (reachable[pos.first][pos.second]) {
        cnt--;
        for (pair<int, int> dir : dirs) {
            dfs({pos.first + dir.first, pos.second + dir.second});
        }
    }
}

int main() {
    // !offline algorithm, do it in reverse with flood fill (directionality makes it difficult though)
    cin >> n >> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = -1;

    for (int i = 0; i < q; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;

        int x;
        if (c == 'U') x = 0;
        if (c == 'R') x = 1;
        if (c == 'D') x = 2;
        if (c == 'L') x = 3;
        arr[a][b] = x;
        queries.push_back({{a, b}, x});
    }

    // TODO add code to instantiate reachable properly
    // TODO set cnt to the amount of values which are unreachable
    cnt = n * n;
    for (int i = 0; i < n; i++) {
        dfs({0, i});
        dfs({i, 0});
        dfs({n - 1, i});
        dfs({i, n - 1});
    }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << reachable[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = q - 1; i >= 0; i--) {
        pair<int, int> pos = queries[i].first;
        arr[pos.first][pos.second] = -1;
        ans[i] = cnt;
        if (reachable[pos.first][pos.second]) continue;

        dfs(pos);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}