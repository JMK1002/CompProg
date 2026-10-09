//
// Created by JMKov on 12/3/2023.
//
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
//    int arr[n];
    stack<pair<int, int>> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        while (!s.empty() && s.top().first < v) {
            ans += i - s.top().second + 1;
            s.pop();
        }
        if (!s.empty()) ans += i - s.top().second + 1;
        s.emplace(v, i);
    }
    cout << ans << endl;
    return 0;
}