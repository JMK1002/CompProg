//
// Created by JMKov on 6/6/2023.
//
#include <iostream>
#include <array>

using namespace std;

bool solve(string s, string p, int version, int *arr) {
    int ptr = 0;
    for (int i = 0; i < version; i++) {
        s[arr[i]] = ' ';
    }
    for (int i = 0; i <= s.size(); i++) {
        if (p[ptr] == s[i]) ptr++;
        if (ptr == p.size()) return true;
    }
    return false;
}

int main() {
    string s;
    string p;
    cin >> s >> p;
    const int n = s.size();
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
//    for (string s : versions) {
//        cout << s << endl;
//        cout << solve(s, p) << endl;
//    }
    int low = 0;
    int high = n;
    while (low < high) {
        int mid = (low + high) / 2;
        bool b = solve(s, p, mid, arr);
//        cout << b << " " << mid << endl;
        if (b) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    low -= !solve(s, p, low, arr);
    cout << low << endl;
    return 0;
}
