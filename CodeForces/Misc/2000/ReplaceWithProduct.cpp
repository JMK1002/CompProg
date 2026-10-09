//
// Created by JMKov on 5/24/2024.
//
#include <iostream>
#include <vector>

using namespace std;

long long arr[200004];
long long prep[200004];
long long pres[200004];
vector<long long> inds;

void solve() {
    long long n = 200000;
    cin >> n;
    vector<long long> asdfff = {399999, 10737, 24124, 43294, 146485, 158509, 577901, 608007, 734433, 1380130, 1569797, 1588375, 3314017, 3397917, 20648881, 89478485};
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
//        if (i < asdfff.size()) arr[i] = asdfff[i];
//        else arr[i] = 268435455;
//        arr[i] = rand() % 100000000 + 1;
    }
    long long prod = 1;
    long long cnt = 0;
    bool work = false;
    for (long long i = 0; i < n; i++) {
        prod *= arr[i];
        if (prod > 1827432) {
            work = true;
            break;
        }
    }
    for (long long i = 0; i < n; i++) cnt += (arr[i] != 1);
    if (prod > 1000000) {
        work = true;
    }
    if (work) {
        long long l = 0;
        long long r = 0;
        for (long long i = 0; i < n; i++) {
            if (arr[i] != 1) {
                l = i;
                break;
            }
        }
        for (long long i = n - 1; i >= 0; i--) {
            if (arr[i] != 1) {
                r = i;
                break;
            }
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
    else if (cnt == 0) {
        cout << "1 1" << endl;
    }
    else {
        for (long long i = 0; i < n; i++) if (arr[i] != 1) inds.push_back(i);
        prep[0] = 1;
        for (long long i = 1; i <= n; i++) {
            prep[i] = prep[i - 1] * arr[i - 1];
            pres[i] = pres[i - 1] + arr[i - 1];
        }
        pair<long long, long long> ans = {0, 0};
        long long mx = 0;
        for (long long i = 0; i < inds.size(); i++) {
            for (long long j = i; j < inds.size(); j++) {
                long long cand = pres[n] - (pres[inds[j] + 1] - pres[inds[i]]) + (prep[inds[j] + 1] / prep[inds[i]]);
                if (cand > mx) {
                    ans = {i, j};
                    mx = cand;
                }
            }
        }
        cout << inds[ans.first] + 1 << " " << inds[ans.second] + 1 << endl;
        for (long long i = 0; i <= n; i++) {
            prep[i] = 0;
            pres[i] = 0;
        }
    }
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
    }
    inds.clear();
}

int main() {
    cin.tie();
    cout.tie();
    istream::sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}