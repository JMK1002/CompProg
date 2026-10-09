//
// Created by JMKov on 8/21/2023.
//
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    int arr[n];
    s.insert(-1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int v = arr[i] / 12;
        s.insert(v);
    }
    sort(arr, arr + n);
    int prev = -3;
    vector<int> dist;
    int cnt = 0;
    for (int i : s) {
        if (prev == -3) {
            prev = i;
            continue;
        }
        dist.push_back(i - prev - 1);
        prev = i;
        cnt++;
    }
    int sub = 0;
    sort(dist.begin(), dist.end());
    for (int i = 0; i < min(k - 1, (int) dist.size()); i++) {
        sub += dist[dist.size() - i - 1] * 12;
    }
//    for (int i : dist) cout << i << " ";
//    cout << endl;
//    cout << sub << endl;
    cout << (arr[n - 1] / 12 + 1) * 12 - sub << endl;
    return 0;
}
// 3 7 8