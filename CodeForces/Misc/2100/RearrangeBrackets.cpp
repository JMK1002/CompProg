//
// Created by JMKov on 7/10/2024.
//
#include <iostream>
#include <stack>

using namespace std;

long long n, k;
long long pr[200005];
long long cnt[200005];
stack<long long> st;
string s;

void solve() {
    cin >> k >> s;
    n = s.size();
    if (k * 2 >= n) {
        cout << 0 << endl;
        return;
    }
    for (long long j = 0; j < k; j++) {
        for (long long i = 0; i < n - j * 2; i++) {
            if (s[i] == '(') st.push(i);
            else {
                pr[i] = st.top();
                pr[st.top()] = i;
                cnt[i] = (i - st.top()) / 2;
                cnt[st.top()] = (i - st.top()) / 2;
                st.pop();
            }
        }
        long long mx = -1;
        long long ind = 0;
        for (long long i = 0; i < n - j * 2; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ind = i;
            }
        }
//        cout << ind << " " << pr[ind] << endl;
        s.erase(max(ind, pr[ind]), 1);
        s.erase(min(ind, pr[ind]), 1);
    }

    for (long long i = 0; i < n - k * 2; i++) {
        if (s[i] == '(') st.push(i);
        else {
            pr[i] = st.top();
            pr[st.top()] = i;
            cnt[i] = (i - st.top()) / 2;
            cnt[st.top()] = (i - st.top()) / 2;
            st.pop();
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n - k * 2; i++) {
        ans += cnt[i];
    }
    cout << ans / 2 << endl;

    for (long long i = 0; i <= n; i++) {
        pr[i] = 0;
        cnt[i] = 0;
    }
    while (!st.empty()) st.pop();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}