#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100005];
vector<pair<pair<int, int>, int>> trees;
set<pair<int, pair<int, int>>> events; // ! x pos, type, index from input
int cnt[100005];
int canRemove[100005];
int corresponding[100005];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        events.insert({arr[i], {1, i}});
    }
    for (int i = 0; i < k; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        trees.push_back({{u, v}, t});
        events.insert({u, {0, i}});
        events.insert({v, {2, i}});
        canRemove[i] = (lower_bound(arr, arr + n, v + 1) - lower_bound(arr, arr + n, u)) - t;
    }
    set<pair<int, int>> run;
    int ans = 0;
    for (pair<int, pair<int, int>> e : events) {
        if (e.second.first == 0) {
            run.insert({canRemove[e.second.second] + ans, e.second.second});
            corresponding[e.second.second] = canRemove[e.second.second] + ans;
        }
        else if (e.second.first == 2) run.erase({corresponding[e.second.second], e.second.second});
        else {
            if (run.empty() || run.begin()->first > ans) ans++;
        }
    }
    
    cout << ans << endl;

    events.clear();
    for (int i = 0; i <= max(n, k); i++) {
        arr[i] = 0;
        cnt[i] = 0;
        corresponding[i] = 0;
    }
}

int main() {
    // ! pretty sure its just scan with events
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 5 3
// 1 2 3 4 5
// 1 2 1
// 3 5 2
// 2 2 1