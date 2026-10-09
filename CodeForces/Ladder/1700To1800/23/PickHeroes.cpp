//
// Created by JMKov on 6/14/2023.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int pows[100000];

bool compare(int a, int b) {
    return pows[a - 1] > pows[b - 1];
}

int main() {
    int n, m, t;
    cin >> n >> m;
    bool explored[2 * n];
    int vals[m];
    map<int, int> pairs;
    for (int i = 0; i < 2 * n; i++) {
        explored[i] = false;
        cin >> pows[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        pairs[a] = b;
        pairs[b] = a;
        if (pows[a - 1] > pows[b - 1]) {
            vals[i] = a;
        }
        else {
            vals[i] = b;
        }
    }
    cin >> t;
    int order[2 * n];
    for (int i = 0; i < 2 * n; i++) order[i] = i + 1;
    sort(order, order + 2 * n, compare);
    int ptr = 0;
    int sortedPtr = 0;
    if (t == 1) {
        if (ptr == m) {
            cout << order[sortedPtr] << endl;
            explored[order[sortedPtr] - 1] = true;
        }
        else {
            cout << vals[ptr] << endl;
            explored[vals[ptr] - 1] = true;
        }
    }
    for (int i = 0; i < n - (t == 1); i++) {
        int x;
        cin >> x;
        if (x == -1) return 0;
        explored[x - 1] = true;
        while (ptr < m && explored[vals[ptr] - 1]) ptr++;
        while (sortedPtr < 2 * n && explored[order[sortedPtr] - 1]) sortedPtr++;
        if (pairs[x] != 0 && ptr == m && !explored[pairs[x] - 1]) {
            cout << pairs[x] << endl;
            explored[pairs[x] - 1] = true;
        }
        else if (ptr == m) {
            cout << order[sortedPtr] << endl;
            explored[order[sortedPtr] - 1] = true;
        }
        else if (pairs[x] == 0 || explored[pairs[x] - 1]) {
            cout << vals[ptr] << endl;
            explored[vals[ptr] - 1] = true;
        }
        else {
            cout << pairs[x] << endl;
            explored[pairs[x] - 1] = true;
        }
        cout.flush();
    }
    if (t == 1) {
        int a;
        cin >> a;
    }
    return 0;
}