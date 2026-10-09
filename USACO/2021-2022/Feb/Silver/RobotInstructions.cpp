//
// Created by JMKov on 12/10/2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;


//long long main() {
//    istream::sync_with_stdio(0);
//    cin.tie();
//    long long n, a, b;
//    cin >> n >> a >> b;
//
//    map<pair<long long, long long>, vector<long long>> reached;
//    map<pair<long long, long long>, vector<long long>> newReached;
//
//    long long xs = 0;
//    long long ys = 0;
//
//    pair<long long, long long> pts[n];
//    for (long long i = 0; i < n; i++) {
//        cin >> pts[i].first >> pts[i].second;
//        xs += pts[i].first;
//        ys += pts[i].second;
//    }
//    reached[{0, 0}] = {-1};
//
//    long long ans[n];
//    for (long long & i : ans) i = 0;
//    for (long long i = 0; i < (n / 2) + (n & 1); i++) {
//        for (pair<pair<long long, long long>, vector<long long>> j : reached) {
////            if (j.first.first == a && j.first.second == b || j.first.first == xs - a && j.first.second == ys - b) continue;
//            for (long long k = 0; k < n; k++) {
//                long long amnt = distance(j.second.begin(), lower_bound(j.second.begin(), j.second.end(), k - 0.5));
//                if (amnt == 0) continue;
//
//                long long index = distance(newReached[{j.first.first + pts[k].first, j.first.second + pts[k].second}].begin(),
//                                      lower_bound(
//                        newReached[{j.first.first + pts[k].first, j.first.second + pts[k].second}].begin(),
//                        newReached[{j.first.first + pts[k].first, j.first.second + pts[k].second}].end(),
//                        k));
//
//                for (long long asdf = 0; asdf < amnt; asdf++) {
//                    newReached[{j.first.first + pts[k].first, j.first.second + pts[k].second}].insert(
//                            newReached[{j.first.first + pts[k].first, j.first.second + pts[k].second}].begin() + index, k);
//                }
//            }
//        }
//        reached = newReached;
//        newReached.clear();
//        ans[i] = reached[{a, b}].size();
//        ans[n - i - 1 - (n & 1)] = reached[{xs - a, ys - b}].size();
//        cout << reached[{a, b}].size() << " ";
//        cout << reached[{xs - a, ys - b}].size() << endl;
//        if (reached[{a, b}].empty()) reached.erase({a, b});
//        if (reached[{xs - a, ys - b}].empty()) reached.erase({xs - a, ys - b});
//    }
//    for (long long i : ans) {
//        cout << i << endl;
//    }
//    return 0;
//}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();

    long long n, a, b;
    cin >> n >> a >> b;
    pair<long long, long long> pts[n];

    long long xs = 0;
    long long ys = 0;

    for (long long i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
        xs += pts[i].first;
        ys += pts[i].second;
    }
    long long ans[n];
    for (long long i = 0; i < n; i++) ans[i] = 0;

    multiset<pair<pair<long long, long long>, long long>> s1;
    multiset<pair<pair<long long, long long>, long long>> s2;
    for (long long i = 0; i < (1 << (n / 2)); i++) {
        long long btCnt = __builtin_popcount(i);
        long long x = 0;
        long long y = 0;
        for (long long j = i, cnt = 0; j > 0; j >>= 1, cnt++) {
            x += (j & 1) * pts[cnt].first;
            y += (j & 1) * pts[cnt].second;
        }
        s1.insert({{x, y}, btCnt});
    }
    for (long long i = 0; i < (1 << (n - n / 2)); i++) {
        long long btCnt = __builtin_popcount(i);
        long long x = 0;
        long long y = 0;
        for (long long j = i, cnt = n / 2; j > 0; j >>= 1, cnt++) {
            x += (j & 1) * pts[cnt].first;
            y += (j & 1) * pts[cnt].second;
        }
        s2.insert({{x, y}, btCnt});
    }
    for (pair<pair<long long, long long>, long long> i : s1) {
        auto end = s2.lower_bound({{a - i.first.first, b - i.first.second}, 100000000000});
        auto start = s2.lower_bound({{a - i.first.first, b - i.first.second}, 0});
        while (start != end) {
            ans[max((long long) 0, i.second + start->second - 1)]++;
            start++;
        }

//        if ((*t).first.first == (a - i.first.first) && (*t).first.second == (b - i.first.second)) {
//            cout << (*t).first.first << " " << (*t).first.second << " " << (*t).second << endl;
//            ans[i.second + (*t).second]++;
//        }
    }
    for (long long i : ans) cout << i << endl;
    return 0;
}