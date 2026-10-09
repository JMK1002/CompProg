//
// Created by JMKov on 4/9/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//bool compare(pair<int, int> a, pair<int, int> b) {
//    return a.first < b.second;
//}

//void dfs(int node, vector<vector<int>> connections, int depth, int *nodeDepths) {
//    nodeDepths[node] = depth;
//    for (int i : connections[node]) {
//        if (nodeDepths[i] != -1) {
//            continue;
//        }
//        dfs(i, connections, depth + 1, nodeDepths);
//    }
//}

int main() {
    int n;
    cin >> n;
    int nodeDepths[n];
    vector<vector<int>> connections(n);
    nodeDepths[0] = 1;
    for (int i = 0; i < n; i++) {
        nodeDepths[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
//        a = i + 1;
//        b = i + 2;
        a--;
        b--;
        connections[a].insert(connections[a].end(), b);
        connections[b].insert(connections[b].end(), a);
    }

    queue<int> q;
    q.push(0);
    int depth = 1;
    while (q.size() != 0) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int val = q.front();
            q.pop();
            nodeDepths[val] = depth;
            for (int j = 0; j < connections[val].size(); j++) {
                if (nodeDepths[connections[val][j]] != -1) {
                    continue;
                }
                q.push(connections[val][j]);
            }
        }
        depth++;
    }
    int layerSizes[depth];
    for (int i = 0; i < depth; i++) {
        layerSizes[i] = 0;
    }
    for (int i : nodeDepths) {
        layerSizes[i - 1]++;
    }
//    for (int i : layerSizes) {
//        cout << i << " ";
//    }
//    cout << endl;
    int red = 0;
    int blue = 0;
    for (int i = 0; i < depth; i++) {
        if (i % 2 == 0) {
            red += layerSizes[i];
        }
        else {
            blue += layerSizes[i];
        }
    }
    cout << (long long) red * blue - n + 1 << endl;
    return 0;
}