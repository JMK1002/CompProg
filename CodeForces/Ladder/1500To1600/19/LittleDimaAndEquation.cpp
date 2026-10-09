//
// Created by JMKov on 5/10/2023.
//
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> ans;
    for (long long i = 1; i <= 81; i++) {
        long long out = b * (long long) pow(i, a) + c;
        string s = to_string(out);
        long long sum = 0;
        for (char casdf : s) {
            sum += (casdf - '0');
        }
        if (sum == i) {
            ans.push_back(out);
        }
    }
    for (long long i = 0; i < ans.size(); i++) {
        if (ans[i] <= 0 || ans[i] >= 1000000000) {
            ans.erase(ans.begin() + i);
            i--;
        }
    }
    cout << ans.size() << endl;
    for (long long i : ans) {
        cout << i << " ";
    }
    return 0;
}