//
// Created by JMKov on 7/7/2024.
//
#include <iostream>
#include <vector>

using namespace std;

long long n, tot, goal;
long long arr[200005][3];
vector<long long> ans;
long long perm[3];

bool work() {
    ans.clear();
    long long run = 0;
    long long cnt = 0;
    for (long long i = 0; i < n && cnt < 3; i++) {
        run += arr[i][perm[cnt]];
        if (run >= goal) {
            ans.push_back(i);
            cnt++;
            run = 0;
        }
    }
    return (ans.size() == 3);
}

void solve() {
    cin >> n;
    for (long long j = 0; j < 3; j++) for (long long i = 0; i < n; i++) cin >> arr[i][j];
    for (long long i = 0; i < n; i++) tot += arr[i][0];
    goal = tot / 3 + (tot % 3 != 0);
    for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < 3; j++) {
            for (long long k = 0; k < 3; k++) {
                if (i == j || i == k || j == k) continue;
//                cout << i << " " << j << " " << k << endl;
                perm[0] = i;
                perm[1] = j;
                perm[2] = k;
                if (work()) {
                    pair<long long, long long> fin[3] = {{1, ans[0] + 1}, {ans[0] + 2, ans[1] + 1}, {ans[1] + 2, n}};
                    for (long long a = 0; a < 3; a++) {
                        for (long long b = 0; b < 3; b++) {
                            if (perm[b] == a) cout << fin[b].first << " " << fin[b].second << " ";
                        }
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
        tot = 0;
        goal = 0;
    }
    return 0;
}