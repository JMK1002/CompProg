//
// Created by JMKov on 6/19/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        long long s = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int i;
        for (i = 0; i < n && arr[i] != 0; i++){
            s += arr[i];
            ans += (s == 0);
        }
        while (i < n) {
            map<long long, int> mp;
            i++;
            s = 0;
            for (; i < n && arr[i] != 0; i++) {
                s += arr[i];
                mp[s]++;
            }
            int mx = 0;
            long long index = 0;
            for (pair<long long, int> p: mp) {
                if (p.second > mx) {
                    mx = p.second;
                    index = p.first;
                }
            }
            mx = max(mx, mp[0] + 1);
            ans += mx;
//            cout << mx << " " << index << " " << i << endl;
        }
        cout << ans << endl;
    }
    return 0;
}