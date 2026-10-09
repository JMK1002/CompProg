//
// Created by JMKov on 8/4/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    string s;
    cin >> s;
    int n = s.size();
    if (n <= 3) {
        cout << s[0] << endl;
        return 0;
    }
    string ans;
    for (int j = 0; j < n / 2; j += 2) {
        int cnt[3];
        for (int i = 0; i < 3; i++) cnt[i] = 0;
        cnt[s[j] - 'a']++;
        cnt[s[j + 1] - 'a']++;
        cnt[s[n - j - 1] - 'a']++;
        cnt[s[n - j - 2] - 'a']++;
        for (int i = 0; i < 3; i++) if (cnt[i] == 2) {
            if (n - j - j >= 4) ans += (char) (i + 'a');
            break;
        }
    }
    string basdf = ans;
    reverse(basdf.begin(), basdf.end());
    if ((n & 1) || ((n / 2) & 1)) ans += s[n / 2];
    ans += basdf;
    cout << ans << endl;
    return 0;
}