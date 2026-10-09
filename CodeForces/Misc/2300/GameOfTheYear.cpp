#include <iostream>
#include <vector>
using namespace std;

int n;
pair<int, int> arr[200005];
int dx[200005];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    for (int i = 0; i < n; i++) {
        if (arr[i].first > arr[i].second) {
            dx[arr[i].second]++;
            dx[arr[i].first]--;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) dx[i] += dx[i - 1];
    for (int k = 1; k <= n; k++) {
        bool works = true;
        for (int j = 0; j <= n; j += k) {
            works &= (dx[j] == 0);
        }
        if (works) ans.push_back(k);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;

    for (int i = 0; i <= n; i++) {
        arr[i] = {0, 0};
        dx[i] = 0;
    }
    ans.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}