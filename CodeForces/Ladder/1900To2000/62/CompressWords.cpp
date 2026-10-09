//
// Created by JMKov on 8/14/2023.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
//    for (int i : pi) cout << i << " ";
//    cout << endl;
    return pi;
}

string arr[100003];

string solve(int n) {
    string ans = arr[0];
    for (int i = 1; i < n; i++) {
        int res = kmp(arr[i] + "_" + ans.substr(max(0, (int) ans.size() - (int) arr[i].size()), min(ans.size(), arr[i].size())))[arr[i].size() + min(ans.size(), arr[i].size())];
//        cout << res << endl;
        ans += arr[i].substr(res, arr[i].size() - res);
//        cout << ans << endl;
    }
    return ans;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = "123456789";
    }
    cout << solve(n) << endl;
    return 0;
}