#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    string s;
    int lvls[26] = { 0 };
    cin >> n >> k >> s;
    for (int i = 0; i < n - k + 1; i++) {
        bool allSame = true;
        for (int j = 0; j < k; j++) {
            if (s[i + j] != s[i]) {
                allSame = false;
                i += j - 1;
                j = k;
            }
        }

        if (allSame) {
            lvls[s[i] - 'a']++;
            i += k;
            i--;
        }
    }
    int mx = 0;
    for (int i = 0; i < 26; i++) {
        mx = max(lvls[i], mx);
    }
    cout << mx << endl;
    return 0;
}