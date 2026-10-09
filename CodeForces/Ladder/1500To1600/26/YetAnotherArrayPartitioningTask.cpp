//
// Created by JMKov on 5/13/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> arr(0);
bool compare(int a, int b) {
    return arr[a] < arr[b];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(pos.begin(), pos.end(), compare);
    vector<int> index(n);
    for (int i = 0; i < n; i++) {
        index[pos[i]] = i;
    }
    int v = n - m * k;
    int count = 0;
    vector<int> ans;
    long long asdf = 0;
    for (int i = n - 1; i >= v; i--) {
        asdf += arr[pos[i]];
    }
//    for (int i : index) cout << i << " ";
    for (int i = 0; i < n; i++) {
        if (count >= m) {
            ans.push_back(i);
            count = 0;
        }
        count += (index[i] >= v);
    }
    cout << asdf << endl;
    for (int i = 0; i < k - 1; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}