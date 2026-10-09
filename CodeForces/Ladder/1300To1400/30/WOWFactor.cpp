//
// Created by JMKov on 4/11/2023.
//
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    long long count = 0;
    long long total = 0;
    long long ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'v' && s[i + 1] == 'v') {
            total++;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v' && s[i + 1] == 'v') {
            count++;
        }
        if (s[i] == 'o') {
            ans += count * (total - count);
        }
    }
    cout << ans << endl;
    return 0;
}