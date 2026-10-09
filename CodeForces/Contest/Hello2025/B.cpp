#include <iostream>
#include <map>
#include <set>
using namespace std;

int n, k;
int arr[100005];
map<int, int> cnt;

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    set<pair<int, int>> st;
    for (pair<int, int> p : cnt) {
        st.insert({p.second, p.first});
    }
    int sum = 0;
    while (!st.empty() && sum <= k) {
        sum += st.begin()->first;
        st.erase(st.begin());
    }
    cout << st.size() + 1 << endl;
    cnt.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}