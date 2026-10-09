//
// Created by JMKov on 12/3/2023.
//
#include <iostream>
#include <queue>
#include <map>

using namespace std;

const long long INF = INT64_MAX;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    map<long long, bool> explored;
    queue<long long> q;
    q.push(a);
    long long ans = 0;
    bool cont = true;
    while (cont) {
        long long sz = q.size();
        for (long long i = 0; i < sz; i++) {
            long long v = q.front();
            q.pop();
            if (v < b && !explored[v << 1]) {
                q.push(v << 1);
                cont = cont && (v << 1) != b;
                explored[v << 1] = true;
            }
            if (!(v & 1) && !explored[v >> 1]) {
                q.push(v >> 1);
                cont = cont && (v >> 1) != b;
                explored[v >> 1] = true;
            }
            if (!explored[v + 1]) {
                q.push(v + 1);
                cont = cont && (v + 1) != b;
                explored[v + 1] = true;
            }
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// d[