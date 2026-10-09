//
// Created by JMKov on 4/18/2023.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int explored[n];
    vector<vector<int>> input(n);
    vector<vector<int>> graph(m, vector<int>(0));
    for (int i = 0; i < n; i++) {
        explored[i] = false;
        int k;
        cin >> k;
        input[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            int lang;
            cin >> lang;
            lang--;
            input[i][j] = lang;
            graph[lang].insert(graph[lang].begin(), i);
        }
    }
    int ans = 0;
    int lowestUnexplored = 0;
    queue<int> q; // q of people to bfs
    while (lowestUnexplored < n) {
        q.push(lowestUnexplored);
        explored[lowestUnexplored] = true;
        while (!q.empty()) {
//            cout << "SDFDS" << endl;
            int person = q.front();
            q.pop();
            for (int i = 0; i < input[person].size(); i++) {
                int lang = input[person][i];
                for (int j = 0; j < graph[lang].size(); j++) {
                    int connectedPerson = graph[lang][j];
                    if (!explored[connectedPerson]) {
                        q.push(connectedPerson);
                        explored[connectedPerson] = true;
                    }
                }
            }
        }
        while (lowestUnexplored < n && explored[lowestUnexplored]) {
            lowestUnexplored++;
        }
        ans++;
    }
    for (int i = 0; i < n; i++) {
        if (!input[i].empty()) {
            cout << ans - 1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}