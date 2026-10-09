#include <iostream>
#include <set>
using namespace std;

long long n, q;
string s;
long long arr[200005];
bool dirs[200005];
long long connections[200005];
bool checked[200005];
bool perm[200005];
set<long long> zeros;

void asdf(long long ind) {
    // if (dirs[ind]) {
    //     if (connections[ind - 1] == 0) zeros.erase(ind - 1);
    //     if (connections[ind] == 1 && !perm[ind]) zeros.insert(ind);
    //     connections[ind - 1]++;
    //     connections[ind]--;
    // }
    // else {
    //     if (connections[ind] == 0) zeros.erase(ind);
    //     if (connections[ind - 1] == 1 && !perm[ind - 1]) zeros.insert(ind - 1);
    //     connections[ind - 1]--;
    //     connections[ind]++;
    // }
    dirs[ind] = !dirs[ind];
    if (!dirs[ind] && dirs[ind + 1] && !perm[ind]) zeros.insert(ind);
    else zeros.erase(ind);
    if (!dirs[ind - 1] && dirs[ind] && !perm[ind - 1]) zeros.insert(ind - 1);
    else zeros.erase(ind - 1);
}

void solve() {
    cin >> n >> q;
    for (long long i = 0, p2 = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        checked[arr[i]] = true;
        while (checked[p2]) p2++;
        perm[i] = (p2 == i + 1);
    }
    cin >> s;
    for (long long i = 0; i < n; i++) {
        dirs[i] = s[i] == 'R';
    }
    for (int i = 1; i < n - 1; i++) {
        if (!dirs[i] && dirs[i + 1] && !perm[i]) zeros.insert(i);
        else zeros.erase(i);
        if (!dirs[i - 1] && dirs[i] && !perm[i - 1]) zeros.insert(i - 1);
        else zeros.erase(i - 1);
    }

    while (q--) {
        long long x;
        cin >> x;
        x--;
        asdf(x);
        // for (int i = 0; i < 10; i++) cout << connections[i] << " ";
        // cout << endl;
        cout << (zeros.empty() ? "YES" : "NO") << endl;
    }

    for (long long i = 0; i <= n + 3; i++) {
        arr[i] = 0;
        dirs[i] = false;
        connections[i] = 0;
        checked[i] = false;
        perm[i] = false;
    }
    zeros.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// 5 10
// 3 2 1 4 5
// RRLLL
// 4ghhhhjhu

