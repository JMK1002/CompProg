//
// Created by JMKov on 8/8/2024.
//
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1000000000;

long long n;
string s[2];
vector<long long> pos[2][2]; // pos[i][j] is i = top/bottom, j = prof
long long ind[2][2];
bool explored[2004];
long long ptr[2004];
long long in[2004];
vector<pair<long long, long long>> ans;

int main() {
    cin >> n >> s[0] >> s[1];
    for (long long i = 0; i < n; i++) ptr[i] = INF;
    for (long long i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) {
            if (s[0][i] == 'M') pos[0][0].push_back(i);
            else if (s[0][i] == 'C') pos[0][1].push_back(i);
        }
        else in[i]++;
    }
    long long asdf = 0;
    while (asdf != n) {
        while (asdf < n && (s[1][asdf] == '-' || s[0][asdf] != '-')) asdf++;
        if (asdf == n) break;
        long long p = asdf;
        do {
            bool prof = s[1][p] == 'C';
            if (ind[0][prof] == pos[0][prof].size()) break;
            ptr[p] = pos[0][prof][ind[0][prof]];
            p = ptr[p];
            in[p]++;
            ind[0][prof]++;
        } while (s[1][p] != '-');
        asdf++;
    }
    for (long long i = 0; i < n; i++) {
        if (in[i] == 0) {
            ans.push_back({0, i});
            long long p = i;
            while (ptr[p] <= 2000) {
                ans.push_back({1, p});
                p = ptr[p];
                ans.push_back({0, p});
                ans.push_back({2, p});
            }
        }
    }
    cout << ans.size() << endl;
    for (pair<long long, long long> p : ans) {
        if (p.first == 0) cout << "DRIVE " << p.second + 1 << endl;
        else if (p.first == 1) cout << "PICKUP" << endl;
        else cout << "DROPOFF" << endl;
    }
    return 0;
}