//
// Created by JMKov on 4/18/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ans;

void solve() {
    long long n;
    cin >> n;
    long long highest = 1e9;
    while (n > 3) {
        if (n & 1) ans.push_back(1);
        ans.push_back(highest);
        highest--;
        n /= 2;
    }
    if (n == 3) ans.push_back(1);
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (long long i : ans) cout << i << " ";
    cout << endl;
    ans.clear();
}
// 1 2 1 3 1 4 5
// 1 3 4 9 10

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}