//
// Created by JMKov on 3/20/2023.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<pair<int, int>*> points, bool* explored, int point) {
    for (int i = 0; i < points.size(); i++) {
        pair<int, int>* j = points[i];
        if (point == i) {
            continue;
        }
//        cout << point << "   " << i << endl;
//        cout << j->first << " " <<  points[point]-> first << " " << j->second << " " << points[point]->second << endl;
        if ((j->first == points[point]->first || j->second == points[point]->second) && !explored[i]) {
            explored[i] = true;
            dfs(points, explored, i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<pair<int, int>*> pointerPoints(n);
    bool explored[n] = { false };
    for (int i = 0; i < n; i++) {
        cin >> points[i].first;
        cin >> points[i].second;
    }

    for (int i = 0; i < n;i++) {
        pointerPoints[i] = &points[i];
    }
    bool done = false;
    int count = 0;
    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << explored[j] << " ";
//        }
//        cout << endl;
        if (!explored[i]) {
            explored[i] = true;
            dfs(pointerPoints, explored, i);
            count++;
        }
    }
    cout << count - 1 << endl;
    return 0;
}