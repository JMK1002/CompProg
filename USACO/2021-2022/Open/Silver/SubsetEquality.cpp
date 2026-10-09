//
// Created by JMKov on 12/12/2023.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> pos[18][2];
bool connections[18][18];

int main() {
    istream::sync_with_stdio(0);

    string s, t;
    long long q;
    cin >> s >> t >> q;
    long long n = s.size();
    long long m = t.size();

    for (long long i = 0; i < n; i++) {
        pos[s[i] - 'a'][0].push_back(i);
    }
    for (long long i = 0; i < m; i++) {
        pos[t[i] - 'a'][1].push_back(i);
    }

    for (long long i = 0; i < 18; i++) for (long long j = 0; j < 18; j++) {
        connections[i][j] = true;
    }

    for (long long i = 0; i < n; i++) {
        long long c = s[i] - 'a';
        if (pos[c][0].size() != pos[c][1].size()) {
            for (long long j = 0; j < 18; j++) {
                connections[c][j] = false;
                connections[j][c] = false;
            }
            continue;
        }

        long long letterPos = distance(pos[c][0].begin(), lower_bound(pos[c][0].begin(), pos[c][0].end(), i));
        long long ind = pos[c][1][letterPos];
        for (long long j = 0; j < 18; j++) {
            if (!connections[c][j]) continue;
            if (
                distance(pos[j][1].begin(), lower_bound(pos[j][1].begin(), pos[j][1].end(), ind)) !=
                distance(pos[j][0].begin(), lower_bound(pos[j][0].begin(), pos[j][0].end(), i))
            ) {
                connections[c][j] = false;
                connections[j][c] = false;
            }
        }
    }

    for (long long i = 0; i < m; i++) {
        long long c = t[i] - 'a';
        if (pos[c][1].size() != pos[c][0].size()) {
            for (long long j = 0; j < 18; j++) {
                connections[c][j] = false;
                connections[j][c] = false;
            }
            continue;
        }

        long long letterPos = distance(pos[c][1].begin(), lower_bound(pos[c][1].begin(), pos[c][1].end(), i));
        long long ind = pos[c][0][letterPos];
        for (long long j = 0; j < 18; j++) {
            if (!connections[c][j]) continue;
            if (
                    distance(pos[j][1].begin(), lower_bound(pos[j][1].begin(), pos[j][1].end(), i)) !=
                    distance(pos[j][0].begin(), lower_bound(pos[j][0].begin(), pos[j][0].end(), ind))
                    ) {
                connections[c][j] = false;
                connections[j][c] = false;
            }
        }
    }

    while (q--) {
        string a;
        cin >> a;
        set<long long> cs;

        bool works = true;
        for (char c : a) cs.insert(c - 'a');
        for (long long i : cs) {
            for (long long j : cs) {
                if (!connections[i][j] || !connections[j][i]) {
                    works = false;
                    break;
                }
            }
            if (!works) break;
        }

        cout << ((works) ? "Y" : "N");
    }

//    for (long long i = 0; i < 18; i++) {
//        for (long long j = 0; j < 18; j++) cout << connections[i][j] << " ";
//        cout << endl;
//    }

    return 0;
}