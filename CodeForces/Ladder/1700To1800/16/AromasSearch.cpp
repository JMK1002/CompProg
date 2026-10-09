//
// Created by JMKov on 6/11/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int exploreLeft(int index, vector<pair<long long, long long>> points, long long t) {
    int ans = 0;
    long long xs = points[index].first;
    long long ys = points[index].second;
    if (t >= 0) ans++;
    for (int i = index - 1; i >= 0 && t >= 0; i--) {
        long long xo = points[i].first;
        long long yo = points[i].second;
//        cout << xo << " " << yo << " " << xs << " " << ys << " " << endl;
        t -= abs(xo - xs) + abs(yo - ys);
        if (t >= 0) {
            ans++;
        }
        else {
            break;
        }
        xs = xo;
        ys = yo;
    }
//    cout << ans << endl;
    return ans;
}

int exploreRight(int index, vector<pair<long long, long long>> points, long long t) {
    int ans = 0;
    long long xs = points[index].first;
    long long ys = points[index].second;
    if (t >= 0) ans++;
    for (int i = index + 1; i < points.size() && t >= 0; i++) {
        long long xo = points[i].first;
        long long yo = points[i].second;
//        cout << xo << " " << yo << " " << xs << " " << ys << " " << endl;
        t -= abs(xo - xs) + abs(yo - ys);
        if (t >= 0) {
            ans++;
        }
        else {
            break;
        }
        xs = xo;
        ys = yo;
    }
//    cout << ans << endl;
    return ans;
}


int main() {
    long long xo, yo, bx, by, xs, ys, t, ax, ay;
    cin >> xo >> yo >> ax >> ay >> bx >> by >> xs >> ys >> t;
    int ans = 0;
    vector<pair<long long, long long>> points;
    while (xo <= INT64_MAX / ax && yo <= INT64_MAX / ay) {
        points.emplace_back(xo, yo);
//        t -= abs(xo - xs) + abs(yo - ys);
//        if (t >= 0) {
//            ans++;
//        }
        xo *= ax;
        yo *= ay;
        xo += bx;
        yo += by;
    }
    for (int i = 0; i < points.size(); i++) {
        long long dist = abs(points[i].first - xs) + abs(points[i].second - ys);
        ans = max(ans, max(exploreLeft(i, points, t - dist), exploreRight(i, points, t - dist)));
    }
//    cout << index << " " << mn << endl;
//    cout << xs << " " << ys << endl;
    cout << ans << endl;
    return 0;
}