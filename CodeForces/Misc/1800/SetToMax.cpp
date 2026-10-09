//
// Created by JMKov on 4/19/2024.
//
#include <iostream>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

int n;
int a[200005], b[200004];
bool checked[200005];

bool check() {
    // as is a minimum monotonic stack and bs is max
    stack<int> as, bs;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        while (!as.empty() && as.top() <= a[i]) {
            as.pop();
        }
        as.push(a[i]);
        if (as.size() == 1) mx = a[i];



        while (!bs.empty() && bs.top() <= b[i]) {
            bs.pop();
        }
        bs.push(b[i]);
        if (bs.size() == 1 && mx <= b[i] || a[i]) checked[i] = true;
    }

    for (int i = 0; i < n; i++) if (!checked[i]) {
        return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    bool ans = check();
    reverse(a, a + n);
    reverse(b, b + n);
    ans = ans || check();
    cout << ans << endl;
//    auto cmp = [](int a, int b){return a > b;};
//    set<int, decltype(cmp)> q(cmp);


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}