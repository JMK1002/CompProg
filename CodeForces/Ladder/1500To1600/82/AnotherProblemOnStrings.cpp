//
// Created by JMKov on 5/31/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    vector<long long> zeroCount;
    zeroCount.push_back(1);
    for (char c : s) {
        if (c == '0') {
            zeroCount[zeroCount.size() - 1]++;
        }
        else {
            zeroCount.push_back(1);
        }
    }
    long long ans = 0;
    if (k == 0) {
        for (long long i : zeroCount) {
            ans += i * (i - 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = k; i < zeroCount.size(); i++) {
        ans += zeroCount[i] * zeroCount[i - k];
    }
    cout << ans << endl;
    return 0;
}