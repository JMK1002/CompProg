//
// Created by JMKov on 6/10/2023.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int * createSteps(int x, int y) {
    int * minSteps = new int[10];
    for (int i = 0; i < 10; i++) minSteps[i] = -1;
    int depth = 1;
    queue<int> q;
    q.push(x);
    q.push(y);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int v = q.front();
            q.pop();
            if (minSteps[v] != -1) continue;
            minSteps[v] = depth;
            if (minSteps[(v + x) % 10] == -1) {
                q.push((v + x) % 10);
            }
            if (minSteps[(v + y) % 10] == -1) {
                q.push((v + y) % 10);
            }
        }
        depth++;
    }
//    for (int i = 0; i < 10; i++) cout << minSteps[i] << " ";
//    cout << endl;
    return minSteps;
}

int main() {
    createSteps(0, 1);
    string s;
    cin >> s;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int * minSteps = createSteps(i, j);
            char prev = s[0];
            int ans = 0;
            for (int k = 1; k < s.size(); k++) {
                char c = s[k];
                int diff;
                if (prev > c) {
                    diff = c - prev + 10;
                }
                else {
                    diff = c - prev;
                }
                if (minSteps[diff] == -1) {
                    ans = -1;
                    break;
                }
                ans += minSteps[diff];
                ans--;
                prev = c;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}