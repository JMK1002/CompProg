//
// Created by JMKov on 7/30/2024.
//
#include <iostream>
#include <stack>

using namespace std;

long long n;
string s;

void solve() {
    cin >> n >> s;
    for (long long i = 1; i < n; i += 2) {
        if (s[i] == '(') s[i + 1] = ')';
    }
    for (long long i = 0; i < n; i++) {
        if (s[i] == '_') s[i] = '(';
    }
    long long ans = 0;
    stack<long long> st;
    for (long long i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        else {
            long long v = st.top();
            st.pop();
            ans += i - v;
        }
    }
    cout << ans << endl;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}