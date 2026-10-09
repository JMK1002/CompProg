//
// Created by JMKov on 4/24/2023.
//
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    bool explored[20000];
    for (int i = 0; i < 20000; i++) {
        explored[i] = false;
    }
    queue<int> q;
    q.push(n);
    while (true) {
        int a = q.size();
        while (a--) {
            int val = q.front();
            q.pop();
            if (val == 0 || explored[val]) {
                continue;
            }
            explored[val] = true;
            if (val < m) {
                q.push(val * 2);
            }
            // a
            q.push(val - 1);
            if (val == m) {
                cout << ans << endl;
                return 0;
            }
        }
        ans++;
    }
}
