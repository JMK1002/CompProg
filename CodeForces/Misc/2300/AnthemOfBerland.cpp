//
// Created by JMKov on 7/22/2023.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> possibleVals;

void calcPi(string s, int * & pi) {
    int n = s.size();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
//        if (s[pi[i - 1]] == s[i] || (s[i] == '?' && s[pi[i - 1]] != '_')) {
//            pi[i] = pi[i - 1] + 1;
//        }
//        else if (s[i] == '?' && s[pi[i - 1]] == '_') {
//            pi[i] = 1;
//        }
//        else {
        int j = pi[i - 1];
        while (s[j] != '_' || !(j == 0 || s[i] == s[j])) {
            j = pi[j - 1];
        }
        pi[i] = j + (j == 0 ? s[j] == s[i] || s[i] == '?' : 1);
//        }
    }
    for (int i = 0; i < n; i++) cout << pi[i] << " ";
    cout << endl;
}

int main() {
    string s, t;
    cin >> s >> t;
    s = t + "_" + s;
    int n = s.size();
    int * pi;
    pi = new int[n];
    calcPi(s, pi);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (pi[i] == t.size());
    }
    cout << ans << endl;
    return 0;
}
//aaaba???b??b??aaa
//aaa

//??c?????
//abcab

//?????????b?????
//abczcab