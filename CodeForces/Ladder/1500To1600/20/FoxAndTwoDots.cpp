//
// Created by JMKov on 5/11/2023.
//
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int explored[n * m];
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n * m; i++) {
        explored[i] = 0;
    }
    int ptr = 0;
    queue<int> q;
    const int dir[4] = {-1, m, 1, -m};
    while (ptr < m * n) {
        q.push(ptr);
        explored[ptr] = 1;
        int count = 1;
        char color = arr[ptr / m][ptr % m];
        bool asdf = false;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : dir) {
                if ((i + v < 0) || (i + v >= m * n) || (i == 1 && v % m == m - 1) || (i == -1 && v % m == 0) || (arr[(v + i) / m][(v + i) % m] != color)) {
//                    cout << i << " " << v << endl;
                    continue;
                }
                if (explored[i + v] == 0) {
                    q.push(i + v);
                    explored[i + v] = explored[v] + 1;
                    count++;
                }
                else if (explored[i + v] == explored[v] + 1) {
                    asdf = true;
//                    cout << i + v << " " << v << endl;
                }
            }
        }
//        cout << count << " " << asdf << endl;
        if (count >= 4 && asdf) {
            cout << "Yes" << endl;
            return 0;
        }
        while (ptr < n * m && explored[ptr]) {
            ptr++;
        }
    }
//    for (int i : explored) {cout << i << " ";}
//    cout << endl;
    cout << "No" << endl;
    return 0;
}