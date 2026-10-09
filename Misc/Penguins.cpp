#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        for (int l = 1; l <= n; l++) {
            if (d[l-1] < a[i] && a[i] < d[l])
                d[l] = a[i];
        }
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}

void printVector(int n, vector<int> v) {
    for (int i = 0; i < 2 * n - 1; i++) cout << "-";
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (v[j] == i) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2 * n - 1; i++) cout << "-";
    cout << endl;
}

void solve(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);
    int cnt = 0;
    do {
        cnt += lis(v) < 3;
        if (lis(v) < 3) {
            if (rand() % 100 == 0) {
                
                for (int i : v) cout << i << " ";
                cout << endl;

                printVector(n, v);
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << cnt << endl;
}

int main() {
    for (int i = 9; i < 10; i++) {
        solve(i);
    }
}