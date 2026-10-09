//
// Created by JMKov on 2/10/2024.
//
#include <iostream>
#include <stack>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long arr[n];
    long long zp = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = i;
        if (arr[i] == 0) zp = i;
    }
    long long narr[n];
    for (long long i = 0; i < n; i++) narr[i] = arr[(i + zp) % n];
    for (long long i = 0; i < n; i++) arr[i] = narr[i];

    stack<pair<long long, long long>> s;
    long long ans = 0;
    long long rans = 0;
    for (long long i = 0; i < n; i++) {
        while (!s.empty() && s.top().first > arr[i]) {
            long long a = s.top().second;
            long long v = s.top().first;
            s.pop();
            if (s.empty()) {
                rans -= v * (a + 1);
            }
            else {
                rans -= v * (a - s.top().second);
            }
        }
        long long amnt = (s.empty()) ? -1 : i - s.top().second; // shouldnt matter that its -1
        s.emplace(arr[i], i);
        rans += amnt * arr[i];
//        cout << rans << endl;
        ans = max(ans , rans);
    }
    cout << ans + n << endl;


//    for (long long i = 0; i < n; i++) {
//        bool explored[n];
//        for (bool & j : explored) j = false;
//        long long v = 0;
//        for (long long j = 0; j < n; j++) {
//            long long p = (j + i) % n;
//            explored[arr[p]] = true;
//            while (v < n && explored[v]) v++;
//            cout << v << " ";
//        }
//        cout << endl;
//    }

}
//0 0 0 0 1 4 5 8
//0 0 0 1 2 2 2 8
//0 0 1 2 2 2 3 8
//0 1 2 2 2 3 6 8
//1 2 2 2 3 6 7 8
//0 0 0 0 0 0 0 8
//0 0 0 0 0 0 1 8
//0 0 0 0 0 1 4 8

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}