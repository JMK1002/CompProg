#include <iostream>
#include <set>
using namespace std;
//`asdf
int n, m, k;
set<pair<pair<int, bool>, int>> events;
set<pair<int, int>> curr;

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int d, a;

        cin >> d >> a;
        events.insert({{d, true}, a});
        events.insert({{d + k, false}, a});
    }

    int t = (*events.begin()).first.first;
    int cnt = 0;
    int tot = 0;
    for (pair<pair<int, bool>, int> p : events) {
        int nt = p.first.first;
        int a = m * (nt - t);
        while (!curr.empty() && a != 0) {
            pair<int, int> f = (*curr.begin());
            if (a >= f.second) {
                a -= f.second;
                curr.erase(curr.begin());
            }
            else {
                curr.erase(curr.begin());
                curr.insert({f.first, f.second - a});
                a = 0;
            }
        }
        if (k == 0) cnt += (nt - t);
        else cnt += ((nt - t) * m - a) / m;

        if (p.first.second) {
            curr.insert({p.first.first * -1, p.second});
        }
        else {
            if (curr.lower_bound({p.first.first * -1 + k, -1}) != curr.end() && (*curr.lower_bound({p.first.first * -1 + k, -1})).first == p.first.first * -1 + k) {
                curr.erase(curr.lower_bound({p.first.first * -1 + k, -1}));
            }
        }
        
        t = nt;
    }
    cout << cnt << endl;

    events.clear();
    curr.clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}