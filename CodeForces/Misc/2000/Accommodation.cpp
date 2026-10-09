//
// Created by JMKov on 5/26/2024.
//
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int two = 0;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += (s[j] == '1');
        }
        for (int j = 0; j < m - 1; j++) {
            if (s[j] == '1' && s[j] == s[j + 1]) {
                two++;
                j++;
            }
        }
        two = min(two, m / 4);
        ans[0] += cnt - two;
        cnt = 0;
        two = 0;
        for (int j = 0; j < m; j++) {
            cnt += (s[j] == '1');
        }
        for (int j = 0; j < m - 1; j++) {
            if (s[j] == '0' || s[j + 1] == '0') {
                two++;
                j++;
            }
        }
        ans[1] += cnt - max(0, (m / 4 - two));
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}