#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<long long, pair<long long, long long>>> grazed;

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    long long g, n;
    cin >> g >> n;
    for (long long i = 0; i < g; i++) {
        pair<long long, pair<long long, long long>> v;
        cin >> v.second.first >> v.second.second >> v.first;
        grazed.emplace_back(v);
    }

    sort(grazed.begin(), grazed.end());

    long long ans = 0;
    while (n--) {
        pair<long long, long long> coords;
        long long time;
        cin >> coords.first >> coords.second >> time;
        auto ptr = lower_bound(grazed.begin(), grazed.end(), pair<long long, pair<long long, long long>>{time, {INT64_MIN, INT64_MIN}});
        long long ind = ptr - grazed.begin();

        bool innocentA = ind != 0;
        bool innocentB = ind != g;
        if (ind != 0) {
            if ((time - grazed[ind - 1].first) * (time - grazed[ind - 1].first) >= dist(grazed[ind - 1].second, coords)) innocentA = false;
        }
        if (ind != g) {
            if (dist(grazed[ind].second, coords) <= (grazed[ind].first - time) * (grazed[ind].first - time)) innocentB = false;
        }

        ans += innocentA || innocentB;
//        if (innocentA || innocentB) cout << n << endl;
    }
    cout << ans << endl;
    return 0;
}
//2 5
//0 0 100
//50 0 200
//25 0 74
//0 50 50
//1000 1000 0
//50 0 200
//10 0 170
