//
// Created by JMKov on 3/30/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans(0);
    int count = 0;
    for (int i = 1; m >= 0; i++) {
        if (i == a[count]) {
            count++;
            continue;
        }
        m -= i;
        if (m >= 0) {
            ans.insert(ans.end(), i);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}