#include <iostream>
#include <vector>
using namespace std;

long long n;

void solve() {
    cin >> n;
    vector<pair<long long, long long>> st; // time where it dies, color
    for (long long i = 0; i < n; i++) {
        pair<long long, long long> p;
        cin >> p.first >> p.second;
        long long prev = 0;
        while (!st.empty() && (st.back().first < p.first || st.back().second == p.second)) {
            pair<long long, long long> a = st.back();
            st.pop_back();
            if (a.second == p.second) {
                p.first += a.first - prev;
            }
            prev = a.first;
        }
        st.emplace_back(p.first, p.second);
        cout << st[0].first << " ";
    }
    cout << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}