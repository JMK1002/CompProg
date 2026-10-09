//
// Created by JMKov on 6/2/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool why(pair<int, int> point, int x1, int x2, int y1, int y2) {
    return !(point.first == x1 && (point.second <= y2 && point.second >= y1) ||
    point.first == x2 && (point.second <= y2 && point.second >= y1) ||
    point.second == y1 && (point.first <= x2 && point.first >= x1) ||
    point.second == y2 && (point.first <= x2 && point.first >= x1));
}

bool solve(int x1, int x2, int y1, int y2, int m, pair<int, int> points[]) {
    vector<pair<int, int>> balls;
    for (int l = 0; l < m; l++) {
        if (why(points[l], x1, x2, y1, y2)) {
            balls.push_back(points[l]);
        }
    }
    if (balls.size() == 1) {
        cout << balls[0].first << " " << balls[0].second << endl;
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int m = n * 4 + 1;
    pair<int, int> points[m];
    vector<int> x(m);
    vector<int> y(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i].first >> points[i].second;
        x[i] = points[i].first;
        y[i] = points[i].second;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < 16; i++) {
        int vals[4];
        vals[0] = x[(i >> 0) & 1];
        vals[1] = x[((i >> 1) & 1) + m - 2];
        vals[2] = y[(i >> 2) & 1];
        vals[3] = y[((i >> 3) & 1) + m - 2];
        bool b = solve(vals[0], vals[1], vals[2], vals[3], m, points);
        if (b) return 0;
    }
    return 0;
}