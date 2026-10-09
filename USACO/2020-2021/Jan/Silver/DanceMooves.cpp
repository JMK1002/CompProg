//
// Created by JMKov on 8/29/2023.
//
#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    pair<int, int> arr[n];
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    set<int> asdf[n];
    for (int i = 0; i < k; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;

//        asdf[i].insert(i);
        int basdf = v[arr[i].first];
        v[arr[i].first] = v[arr[i].second];
        v[arr[i].second] = basdf;
//        asdf[v[arr[i].first]].insert(arr[i].first);
//        asdf[v[arr[i].second]].insert(arr[i].second);
    }
//    for (int i : v) cout << i << " ";
//    cout << endl;
    int idk[n];
    for (int i = 0; i < n; i++)
    for (int i = 0; i < n; i++) {
        for (int j : asdf[i]) cout << j << " ";
        cout << endl;
    }

    return 0;
}