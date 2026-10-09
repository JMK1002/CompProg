//
// Created by JMKov on 7/3/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        while (!stack.empty() && stack.back() < v) {
            ans = max(ans, v ^ stack.back());
            stack.pop_back();
        }
        if (!stack.empty()) {
            ans = max(ans, v ^ stack.back());
        }
        stack.push_back(v);
    }
    cout << ans << endl;
    return 0;
}