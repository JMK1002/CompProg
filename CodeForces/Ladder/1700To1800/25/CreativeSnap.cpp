//
// Created by JMKov on 6/15/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> positions;
long long a;
long long b;

long long binSearch(long long target, bool dir) {
    long long low = 0;
    long long high = positions.size() - 1;
    double dTar = target - 0.5 + dir;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (positions[mid] < dTar) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    low -= (low - 1 >= 0 && positions[low - 1] >= dTar);
    low += (low < positions.size() && positions[low] <= dTar);
    return low;
}

long long solve(long long start, long long end) {
    long long l = end - start + 1;
    long long count = binSearch(end, 1) - binSearch(start, 0);
//    cout << count << endl;
    if (count == 0) return a;
    else if (start == end) {
        return b * count;
    }
    long long x = solve(start, (start + end) / 2);
    long long y = solve((start + end) / 2 + 1, end);
//    cout << x << endl;
    return min(b * l * count, x + y);
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k;
    cin >> n >> k >> a >> b;
    for (long long i = 0; i < k; i++) {
        int val;
        cin >> val;
//val = i + 1;
        positions.push_back(val);
    }
    sort(positions.begin(), positions.end());
    cout << solve(1, 1 << n) << endl;
//    for (long long i : positions) cout << i << " ";
//    cout << endl;
//    cout << binSearch(positions, 4, false) << endl;
    return 0;
}
//3 4 2 3
//1 5 6 8