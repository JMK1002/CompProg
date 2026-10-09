//
// Created by JMKov on 4/17/2023.
//
#include <iostream>
#include <queue>

using namespace std;

int explored[300000];
int vals[200000];

int main() {
    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; i++) for (int j = c - 1; j >= 0; j--) {
        char asdf;
        cin >> asdf;
        vals[i] += (1 << j) * (asdf == 'G');
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(vals[i]);
        explored[vals[i]] = 1;
//        cout << vals[i] << " ";
    }
//    cout << endl;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int j = 0; j < c; j++) {
            int next = v ^ (1 << j);
            if (explored[next]) continue;
            q.push(next);
            explored[next] = explored[v] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        vals[i] = vals[i] ^ ((1 << c) - 1);
//        cout << vals[i] << " ";
        cout << c + 1 - explored[vals[i]] << endl;
    }
//    cout << endl;
    return 0;
}
//22 16 9
//9 15 22