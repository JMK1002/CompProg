//
// Created by JMKov on 6/30/2024.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long n;
long long arr[5005];
long long cnt[5005];
int works[5005];
int works2[5005];
vector<pair<long long, long long>> vec;
set<pair<long long, long long>> curr; // amnt of cakes eaten, save

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
//         cin >> arr[i];
        arr[i] = i + 1;
        cnt[arr[i]]++;
    }
    sort(arr, arr + n);
    for (long long i = 0; i < n; i++) {
        if (vec.empty() || vec[vec.size() - 1].first != arr[i]) vec.push_back({arr[i], cnt[arr[i]]});
    }
    sort(vec.begin(), vec.end());
//    for (long long i = 0; i < n; i++) cout << arr[i] << " ";
//    cout << endl;
//    for (long long i = 0; i < n; i++) cout << vec[i].first << "," << vec[i].second << "   ";
//    cout << endl;

    for (int i = 0; i <= n; i++) {
        works[i] = -1;
        works2[i] = -1;
    }
    works[0] = 0;
    for (long long i = 0; i < vec.size(); i++) {
        for (int j = 0; j < i    + 4; j++) {
            if (works[j] == -1) continue;
            works2[j + 1] = max(works2[j + 1], works[j] + 1);
            if (works[j] >= vec[i].second) {
                works2[j] = max((long long) works2[j], works[j] - vec[i].second);
            }
        }

        for (int j = 0; j < i + 4; j++) {
            works[j] = works2[j];
            works2[j] = -1;
        }
    }
    for (int i = 0; i <= n; i++) {
        if (works[i] != -1) {
            cout << i << endl;
            break;
        }
    }

    for (long long i = 0; i <= n; i++) {
        cnt[arr[i]] = 0;
        arr[i] = 0;
        works[i] = 0;
        works2[i] = 0;
    }
    vec.clear();
    curr.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 1 3
// 2 3
// 3 3
// 4 1
// 5 1