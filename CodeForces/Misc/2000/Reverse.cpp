//
// Created by JMKov on 6/16/2024.
//
#include <iostream>
#include <set>

using namespace std;

long long x, y;

long long beginCnt(long long a) {
    long long ret = 0;
    while ((((long long) 1 << ret) & a)) {
        ret++;
    }
    return ret;
}

void removeBack(long long &a, long long cnt) {
    a >>= cnt;
}

long long endCnt(long long a) {
    long long mx = 0;
    while ((((long long) 1 << mx) <= a)) {
        mx++;
    }
    mx--;
    long long ans = 0;
    for (long long i = mx; i >= 0 && (((long long) 1 << i) & a); i--) {
        ans++;
    }
    return ans;
}

void removeFront(long long &a, long long cnt) {
    long long mx = 0;
    while ((((long long) 1 << mx) <= a)) {
        mx++;
    }
    mx--;
    for (long long i = mx; i > mx - cnt; i--) {
        a ^= ((long long) 1 << i);
    }
}

int main() {
    cin >> x >> y;
    long long rev = 0;
    long long revOne = 0;
    for (long long i = 0; i < 62 && x >= ((long long) 1 << i); i++) {
        rev *= 2;
        rev += (((long long) 1 << i) & x) != 0;
    }
    for (long long i = 0; i < 62 && (x * 2 + 1) >= ((long long) 1 << i); i++) {
        revOne *= 2;
        revOne += (((long long) 1 << i) & (x * 2 + 1)) != 0;
    }
    long long noZero = 0;
    for (long long i = 0; i < 62 && rev >= ((long long) 1 << i); i++) {
        noZero *= 2;
        noZero += (((long long) 1 << i) & rev) != 0;
    }
    long long yc = y;
    removeBack(yc, beginCnt(yc) - beginCnt(x));
//    cout << yc << endl;
    if (yc == x && !(beginCnt(yc) - beginCnt(x) < 0 || endCnt(yc) - endCnt(x) < 0)) {
        cout << "YES" << endl;
        return 0;
    }
    yc = y;
    if (beginCnt(yc) > 0) {
        removeBack(yc, beginCnt(yc) - beginCnt(x));
        removeFront(yc, endCnt(yc) - endCnt(x));
//    cout << yc << endl;
        if (yc == x && !(beginCnt(yc) - beginCnt(x) < 0 || endCnt(yc) - endCnt(x) < 0)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    yc = y;
    removeBack(yc, beginCnt(yc) - beginCnt(rev));
    removeFront(yc, endCnt(yc) - endCnt(rev));
//    cout << yc << endl;
    if (yc == rev && !(beginCnt(yc) - beginCnt(rev) < 0 || endCnt(yc) - endCnt(rev) < 0)) {
        cout << "YES" << endl;
        return 0;
    }
    yc = y;
    removeBack(yc, beginCnt(yc) - beginCnt(revOne));
    removeFront(yc, endCnt(yc) - endCnt(revOne));
//    cout << yc << endl;
    if (yc == revOne && !(beginCnt(yc) - beginCnt(revOne) < 0 || endCnt(yc) - endCnt(revOne) < 0)) {
        cout << "YES" << endl;
        return 0;
    }
    yc = y;
    removeBack(yc, beginCnt(yc) - beginCnt(noZero));
    removeFront(yc, endCnt(yc) - endCnt(noZero));
//    cout << yc << endl;
    if (yc == noZero && !(beginCnt(yc) - beginCnt(noZero) < 0 || endCnt(yc) - endCnt(noZero) < 0)) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}