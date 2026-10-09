//
// Created by JMKov on 12/16/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<int, int> cnt[5];
int targetsHit[5];
set<int> targets;

int main() {
    int t, n;
    string s;
    cin >> t >> n;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        targets.insert(x);
    }
    cin >> s;

    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') pos--;
        else if (s[i] == 'R') pos++;
        else {
            for (int j = -2; j <= 2; j++) {
                if (targets.find(pos + j) != targets.end()) {
                    cnt[j + 2][pos + j]++;
                    if (cnt[j + 2][pos + j] == 1) targetsHit[j + 2]++;
                }
            }
        }
    }

    int ans = targetsHit[2];

    pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') pos--;
        else if (s[i] == 'R') pos++;

        if (s[i] == 'F') {
            for (int j = -2; j <= 2; j++) {
                if (targets.find(pos + j) != targets.end()) {
                    cnt[j + 2][pos + j]--;
                    if (cnt[j + 2][pos + j] == 0) targetsHit[j + 2]--;
                }
            }
            ans = max(ans, max(targetsHit[1], targetsHit[3]));
        }
        else if (s[i] == 'L') {
            ans = max(ans, max(targetsHit[4],
                    targetsHit[3] + (targets.find(pos + 1) != targets.end() && cnt[3][pos + 1] == 0)
            ));
        }
        else if (s[i] == 'R') {
            ans = max(ans, max(targetsHit[0],
                               targetsHit[1] + (targets.find(pos - 1) != targets.end() && cnt[1][pos - 1] == 0)
            ));
        }
    }
    cout << ans << endl;
    return 0;
}