//
// Created by JMKov on 7/27/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int c3[2003];
int c2[2003];

void init() {
    c3[3] = 1;
    for (int i = 4; i < 2003; i++) {
        c3[i] = (int) ((long long) c3[i - 1] * i / (i - 3));
//        cout << c3[i] << endl;
    }
    c2[2] = 1;
    for (int i = 3; i < 2003; i++) {
        c2[i] = (int) ((long long) c2[i - 1] * i / (i - 2));
    }
}

int main() {
    int n;
    cin >> n;
    init();
    int ans = c3[n];
    pair<int, int> coords[n];
    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    sort(coords, coords + n);
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> count;
        for (int j = i + 1; j < n; j++) {
            int dx = coords[i].first - coords[j].first;
            int dy = coords[i].second - coords[j].second;
            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            count[{dx, dy}]++;
//            if (dx == 1 && dy == 1) cout << i << " " << j << endl;
        }
        for (auto p : count) {
            ans -= c2[p.second];
//            if (p.second != 1) {
//                cout << p.first.first << " " << p.first.second << " " << p.second << " " << i << endl;
//            }
        }
    }
    cout << ans << endl;
    return 0;
}