//
// Created by JMKov on 5/8/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int start = 0, end = n - 1;
    while (start < n && s[start] == '1') {
        start++;
    }
    while (end >= 0 && s[end] == '1') {
        end--;
    }
    int groupCounts[2] = {0, 0};
    groupCounts[s[start] - '0']++;
    for (int i = start + 1; i < end + 1; i++) {
        if (s[i] != s[i - 1]) {
            groupCounts[s[i] - '0']++;
        }
    }
    if (groupCounts[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
//    cout << groupCounts[0] << " " << groupCounts[1] << endl;
    cout << min(y * groupCounts[0], x * groupCounts[1] + y) << endl;
    return 0;
}