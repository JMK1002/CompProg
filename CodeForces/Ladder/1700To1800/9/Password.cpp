#include <bits/stdc++.h>

using namespace std;

vector<int> pref_function(string s) {
    int n = s.size();
    vector<int> pref(n);
    for (int i = 1; i < n; ++i) {
        int last = pref[i - 1];
        while (last != 0 && s[i] != s[last]) {
            last = pref[last - 1];
        }
        pref[i] = last;
        if (s[pref[i]] == s[i])
            ++pref[i];
    }
    return pref;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    auto tmp = pref_function(s);
    vector<int> can_size;
    int i = tmp.back();
    while (i != 0) {
        can_size.push_back(i);
        i = tmp[i - 1];
    }
    reverse(can_size.begin(), can_size.end());
    int r = can_size.size(), l = -1;
    while (r - l > 1) {
        int _m = (l + r) / 2;
        int m = can_size[_m];
        bool can = true;
        for (int i = 0; i < m; ++i) {
            if (s[i] != s[s.size() - m + i])
                can = false;
        }
        auto z = s.substr(0, m) + "#" + s.substr(1, s.size() - 2);
        auto pref = pref_function(z);
        if (can && *max_element(pref.begin(), pref.end()) >= m)
            l = _m;
        else
            r = _m;
    }
    if (l == -1) {
        cout << "Just a legend\n";
        return 0;
    }
    for (int i = 0; i < can_size[l]; ++i)
        cout << s[i];
    cout << '\n';
}