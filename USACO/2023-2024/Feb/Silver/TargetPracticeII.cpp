//
// Created by JMKov on 2/18/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

int solve() {
    int n, x1;
    cin >> n >> x1;
    pair<int, int> top[n];
    int bot[n];
    for (int i = 0; i < n; i++) {
        // y1, y2, x2;
        cin >> bot[i] >> top[i].second >> top[i].first;
    }
    int s[n];
    int neg = 0;
    int pos = 0;
    for (int i = 0; i < 4 * n; i++) {
        cin >> s[i];
        if (s[i] < 0) neg++;
        else if (s[i] > 0) pos++;
    }
    if (max(neg, pos) > 2 * n) return -1;
    sort(s, s + (4 * n));

    for (int i = 0; i < 2 * n; i++) {

    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
//3
//2 1
//1 3 6
//4 6 3
//1 -1 2 -2 3 -3 4 -4
//2 1
//1 3 6
//4 6 3
//1 1 2 2 3 3 4 4
//2 1
//1 3 3
//4 6 3
//1 -1 2 -2 3 -3 4 -4

//17
//-1
//11