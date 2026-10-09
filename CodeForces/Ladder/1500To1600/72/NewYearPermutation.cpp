//
// Created by JMKov on 5/28/2023.
//
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    string binary[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> binary[i];

    queue<int> q;
    int ptr = 0;
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    while(ptr < n) {
        q.push(ptr);
        explored[ptr] = true;
        set<int> asdf;
        asdf.insert(ptr);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (binary[v][i] == '0' || explored[i]) {
                    continue;
                }
                asdf.insert(i);
                explored[i] = true;
                q.push(i);
            }
        }
        vector<int> subArray;
        while (ptr < n && explored[ptr]) ptr++;
        for (int it : asdf) {
            subArray.push_back(arr[it]);
        }
        sort(subArray.begin(), subArray.end());
        int count = 0;
        for (int it : asdf) {
            arr[it] = subArray[count];
            count++;
        }
    }
    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
//5
//1 2 4 5 3
//10010
//00011
//00100
//01101
//01010