//
// Created by JMKov on 3/31/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> a = {
            { 0 },
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
            { 2, 4, 6, 8, 0 },
            { 3, 6, 9, 2, 5, 8, 1, 4, 7, 0 },
            { 4, 8, 2, 6, 0 },
            { 5, 0 },
            { 6, 2, 8, 4, 0 },
            { 7, 4, 1, 8, 5, 2, 9, 6, 3, 0 },
            { 8, 6, 4, 2, 0 },
            { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }
    };
    vector<int> sums = {
            0,
            45,
            20,
            45,
            20,
            5,
            20,
            45,
            20,
            45
    };
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long sum = 0;
        sum += n / ((long long) m * (long long) a[m % 10].size()) * ((long long) sums[m % 10]);
        long long asdf = n / m / (long long) a[m % 10].size() * (long long) a[m % 10].size();
        //cout << asdf << " " << sum << endl;
        for (long long i = asdf; i <= n / m; i++) {
            sum += ((i) % 10 * (m) % 10) % 10;
        }
        cout << sum << endl;
    }
    return 0;
}
