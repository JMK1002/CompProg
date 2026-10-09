//
// Created by JMKov on 6/30/2023.
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long double calcDist (pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    cout.precision(15);
    cin.tie();
    cout.tie();
    pair<int, int> a;
    pair<int, int> b;
    pair<int, int> bin;
    int n;
    cin >> a.first >> a.second >> b.first >> b.second >> bin.first >> bin.second >> n;
    pair<int, int> arr[n];
    long double binDistance[n];
    long double aDistance[n];
    long double bDistance[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        binDistance[i] = calcDist(arr[i], bin);
        aDistance[i] = calcDist(arr[i], a);
        bDistance[i] = calcDist(arr[i], b);
    }
    long double mnA = 0;
    long double mn = 2000000000000;
    long double mn2A = 0;
    long double mnB = 0;
    long double mn2B = 0;
    long double ans = 0;
    int indexA = 0;
    int indexB = 0;
    for (int i = 0; i < n; i++) {
        ans += binDistance[i] * 2;
        long double aDiff = aDistance[i] - binDistance[i];
        long double bDiff = bDistance[i] - binDistance[i];
        if (aDiff < mnA) {
            mn2A = mnA;
            mnA = aDiff;
            indexA = i;
        }
        else if (aDiff < mn2A) {
            mn2A = aDiff;
        }
        if (bDiff < mnB) {
            mn2B = mnB;
            mnB = bDiff;
            indexB = i;
        }
        else if (bDiff < mn2B) {
            mn2B = bDiff;
        }
        mn = min(min(aDiff, bDiff), mn);
    }
    if (mnA == 0 && mnB == 0) {
        ans += mn;
    }
    else if (indexA == indexB) {
        ans += min(mn2A + mnB, mn2B + mnA);
    }
    else {
        ans += mnA + mnB;
    }
//    for (long double i : aDistance) cout << i << " ";
//    cout << endl;
//    for (long double i : bDistance) cout << i << " ";
//    cout << endl;
//    for (long double i : binDistance) cout << i << " ";
//    cout << endl;
//    cout << mnA << " " << mnB << endl;

    cout << ans << endl;
    return 0;
}