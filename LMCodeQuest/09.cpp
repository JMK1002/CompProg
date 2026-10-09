//
// Created by JMKov on 2/24/2024.
//
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    map<string, double> mp;
    for (long long i = 0; i < n; i++) {
        string s;
        double v;
        cin >> s >> v;
        mp[s] = v;
    }
    for (long long i = 0; i < m; i++) {
        string s;
        cin >> s;
        double x, y;
        cin >> x >> y;
        double amnt = mp[s] * x;
        if (amnt >= y) {
            cout << "Infinity" << endl;
            continue;
        }
        double asdf = round((50.0 / (y - amnt)) * 100) / 100;
        long long p1 = (long long) (asdf);
        cout << (long long) (asdf) << "." << ((long long) (asdf * 10)) % 10 << ((long long) (asdf * 100)) % 10 << endl;
//        cout << ((long long) (asdf * 100)) << endl;
//        cout << asdf << endl;
    }
}

int main() {
    cout.precision(20);
    setprecision(20);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//1
//2 5
//Lead 2
//Steel 1.1
//Lead 2 5
//Lead 4 7.5
//Steel 1 5.0
//Steel 1.5 12.5
//Steel 2.5 3.14

//1
//2 1
//Lead 2
//Steel 1.1
//Steel 2.5 3.14


//1
//1 1
//a 0.999999
//a 1 1