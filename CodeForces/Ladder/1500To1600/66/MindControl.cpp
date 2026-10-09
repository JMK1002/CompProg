//
// Created by JMKov on 5/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = 0;
        int asdf[m];
        for (int j = 0; j < m; j++) {
            asdf[j] = max(arr[n - m + j], arr[j]);
        }
//        for (int i : asdf) cout << i << " ";
//        cout << endl;
        for (int i = 0; i <= min(m - 1, k); i++) {
            int aaa = 1000000000;
            for (int j = 0; j < m - min(m - 1, k); j++) {
                aaa = min(aaa, asdf[j + i]);
            }
            ans = max(ans, aaa);
        }
        cout << ans << endl;
    }
    return 0;
}