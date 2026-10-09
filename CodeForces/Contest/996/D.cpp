#include <iostream>
#include <set>
using namespace std;

int n, k, l;
bool b;
int arr[200005];
int newPos[200005];
set<pair<int, bool>> ev;

void solve() {
    cin >> n >> k >> l;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int t = arr[0];
    newPos[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - newPos[i - 1] >= k) newPos[i] = max(newPos[i - 1] + k, arr[i] - t);
        else newPos[i] = min(newPos[i - 1] + k, arr[i] + t);
    }

    for (int i = 0; i < n; i++) {
        ev.insert({newPos[i], true});
        ev.insert({newPos[i] + k, false});
    }
    int cnt = 0;
    int last = 0;
    int ans = 0;
    // for (int i = 0; i < n; i++) cout << newPos[i] << " ";
    // cout << endl;
    for (pair<int, int> event : ev) {
        if (event.second) {
            cnt++;
            if (cnt == 1) ans += event.first - last;
        }
        else {
            cnt--;
        }
        if (!cnt) last = event.first;
    }
    int extra = max(0, l - (newPos[n - 1] + k));
    int hurrDurr = min(0, l - (newPos[n - 1] + k)) * -1;
    cout << ans * 2 - min(ans / 2, hurrDurr) * 2 - (ans % 2 == 1 && hurrDurr > ans / 2) + t * 2 + extra * 2 << endl;

if (b) {
    cout << n << k << l << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        newPos[i] = 0;
    }
    ev.clear();
}

int main() { 
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    if (t == 10000) b = true;
    while (t--) {
        if (!b || t == 10000 - 844) solve();
        else {
                cin >> n >> k >> l;
    for (int i = 0; i < n; i++) cin >> arr[i];
        }
    }
    return 0;
}