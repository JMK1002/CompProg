//
// Created by JMKov on 5/23/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int arr[n - 1];
    arr[0] = 0;
    vector<int> zeros(1, 0);
    int ans = 1;
    bool a = (s[0] - '0');
    for (int i = 1; i < n ; i++) {
        if (s[i] == s[i - 1]) {
            arr[i] = 0;
            zeros.push_back(i);
        }
        else arr[i] = arr[i - 1] + 1;
        if ((s[i] - '0') != a) {
            a = !a;
            ans++;
        }
    }
    if (zeros.size() > 2) {
        cout << ans + 2 << endl;
    }
    else if (zeros.size() == 2) {
        cout << ans + 1  << endl;
    }
    else cout << ans << endl;
    return 0;
}