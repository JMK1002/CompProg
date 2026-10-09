#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    int t;
    while (t--) {
        int l, s;
        cin >> l >> s;
        vector<pair<int, int>> locations(l);
        vector<pair<int, int>> stops(s);
        for (int i = 0; i < l; i++) {
            pair<int, int> a;
            cin >> a.first;
            cin >> a.second;
            locations[i] = a;
        }
        for (int i = 0; i < s; i++) {
            pair<int, int> a;
            cin >> a.first;
            cin >> a.second;
            stops[i] = a;
        }
        bool stuffChanges = true;
        while (stuffChanges) {
            vector<pair<int, int>*> groupings(l);
            for (int i = 0; i < l; i++) {
                pair<int, int> a = locations[i];
                long long minDist = 1000000000000;
                pair<int, int>* stop;
                for (pair<int, int> b : stops) {
                    int d = dist(a, b);
                    if (d < minDist || (d == minDist && (stop->first > b.first || (stop->first == b.first && stop->second > b.second)))) {
                        minDist = d;
                        stop = &b;
                    }
                }
                groupings[i] = stop;
            }
        }
    }
    return 0;
}