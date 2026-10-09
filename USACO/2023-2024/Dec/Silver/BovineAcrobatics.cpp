//
// Created by JMKov on 12/16/2023.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long long INF = INT64_MAX - 100000000;
long long n, m, k;
set<pair<long long, long long>> vals;
map<long long, long long> removed;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cin >> n >> m >> k;
    pair<long long, long long> arr[n]; // first = weight  second = amnt


    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        vals.insert(arr[i]);
    }

    while (m > 0) {
        auto ptr = vals.begin();
        long long lowest = INF;
        while (ptr != vals.end()) {
            lowest = min(lowest, (*ptr).second);

            pair<long long, long long> u = {(*ptr).first + k, 0};
            ptr = vals.lower_bound(u);
        }


        vector<set<pair<long long, long long>>::iterator> del;
        ptr = vals.begin();
        long long amnt = min(m, lowest);
        while (ptr != vals.end()) {
            removed[(*ptr).first] += amnt;
            if (removed[(*ptr).first] == (*ptr).second) del.push_back(ptr);

            pair<long long, long long> u = {(*ptr).first + k, 0};
            ptr = vals.lower_bound(u);
        }

        reverse(del.begin(), del.end());
        for (auto i : del) vals.erase(i);
        m -= amnt;
    }
    long long ans = 0;
    for (pair<long long, long long> i : removed) {
        ans += i.second;
    }
    cout << ans << endl;


    return 0;
}