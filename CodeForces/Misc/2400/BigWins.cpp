#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int&v : a) cin >> v;
        int ans = 0;
        for (int _ : {0,1}) {
            priority_queue<int> pq;
            for (int v : a) {
                if (pq.size() && pq.top() > v) {
                    ans = max(ans, pq.top()-v);
                    pq.pop();
                    pq.push(v);
                }
                pq.push(v);
            }
            reverse(a.begin(), a.end());
        }
        cout << ans << endl;
    }
}
