#include <iostream>
using namespace std;

int n;
pair<int, int> arr[200005];
int cnt[1000000];
bool works[1000000];
int pre[1000000];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first == arr[i].second) {
            works[arr[i].first] = true;
            cnt[arr[i].first]++;
        }
    }

    for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + works[i];
    for (int i = 0; i < n; i++) {
        if (arr[i].first == arr[i].second) {
            if (cnt[arr[i].first] > 1) cout << 0;
            else cout << 1;
        }
        else {
            if (pre[arr[i].second] - pre[arr[i].first - 1] == arr[i].second - arr[i].first + 1) cout << 0;
            else cout << 1;
        }
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        arr[i] = {0, 0};
    }
    for (int i = 0 ;i <= 2 * n; i++) {
        cnt[i] = 0;
        works[i] = 0;
        pre[i] = 0;
    }
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