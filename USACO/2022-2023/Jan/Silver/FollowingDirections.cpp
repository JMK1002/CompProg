//
// Created by JMKov on 12/20/2023.
//
#include <iostream>
using namespace std;

int n;
string arr[1501];
bool explored[1501][1501];
int costs[3002];
int children[1502][1502];
int ans = 0;

int simulate(int x, int y) {
    if (x == n) return costs[y];
    else if (y == n) return costs[n + x];
    return (arr[y][x] == 'R') ? simulate(x + 1, y) : simulate(x, y + 1);
}

void modify(int x, int y, int m) {
    if (x == n) return;
    else if (y == n) return;
    children[y][x] += m;
    if (arr[y][x] == 'R') modify(x + 1, y, m);
    else modify(x, y + 1, m);
}

void dfs(int x, int y) {
    if (explored[y][x]) return;
    explored[y][x] = true;
    if (x != 0 && arr[y][x - 1] == 'R') {
        dfs(x - 1, y);
        children[y][x] += children[y][x - 1];
    }
    if (y != 0 && arr[y - 1][x] == 'D') {
        dfs(x, y - 1);
        children[y][x] += children[y - 1][x];
    }
}

void swap(int x, int y) {
//    int down = -1;
//    if (arr[y][x] == 'D') down = 1;
    int c = children[y][x];
//    children[y][x + 1] += children[y][x] * down;
//    children[y + 1][x] += children[y][x] * down * -1;

    modify(x, y, -1 * c);
    if (arr[y][x] == 'D') arr[y][x] = 'R';
    else arr[y][x] = 'D';
    modify(x, y, c);
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[n - 1][i] == 'D') ans += children[n - 1][i] * costs[n + i];
        if (arr[i][n - 1] == 'R') ans += children[i][n - 1] * costs[i];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cin >> costs[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costs[i + n];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) children[i][j] = 1;

    for (int i = 0; i < n; i++) dfs(i, n - 1);
    for (int i = 0; i < n - 1; i++) dfs(n - 1, i);

    for (int i = 0; i < n; i++) {
        if (arr[n - 1][i] == 'D') ans += children[n - 1][i] * costs[n + i];
        if (arr[i][n - 1] == 'R') ans += children[i][n - 1] * costs[i];
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << children[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << ans << endl;

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        swap(v, u);

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << children[i][j] << " ";
//            }
//            cout << endl;
//        }
        cout << ans << endl;
    }
    return 0;
}
//3
//RRD 4
//RDD 100
//DRD 8
//10 6 8