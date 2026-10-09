//
// Created by JMKov on 7/30/2023.
//
#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ch[1000];
    int dist[1000];
    ch[2] = 1;
    ch[1] = 0;
    ch[0] = 0;
    for (int i = 3; i < 1000; i++) {
        ch[i] = (int) ((long long) ch[i - 1] * i / (i - 2));
    }
    for (int i = 999; i >= 2; i--) {
        dist[i] = n / ch[i];
        n %= ch[i];
    }
    string s = "1";
    for (int i = 0; i < 1000; i++) s += '3';
    for (int i = 999; i >= 2; i--) {
        for (int j = 0; j < dist[i]; j++) {
//            cout << i << " ";
            s.insert(s.begin() + i + 1, '7');
        }
    }
    cout << s << endl;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}