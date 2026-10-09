#include <iostream>
using namespace std;

int n;
int a[200005];
int b[200005];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    int asdf = 0;
    for (int i = 0; i < n; i++) {
        cnt += (a[i] < b[i]);
        if (a[i] < b[i]) asdf = i;
    }
    if (cnt == 0) cout << "YES" << endl;
    else if (cnt >= 2) cout << "NO" << endl;
    else {
        // ! cnt == 1 with asdf being the index
        int amnt = b[asdf] - a[asdf];
        for (int i = 0; i < n; i++) {
            if (i == asdf) continue;
            if (a[i] - amnt < b[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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