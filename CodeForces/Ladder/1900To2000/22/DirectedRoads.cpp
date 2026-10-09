//
// Created by JMKov on 7/27/2023.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    int index[n];
    int explored[n];
    for (int i = 0; i < n; i++) index[i] = -1;
    for (int i = 0; i < n; i++) index[i] = -1;
    int pos = 0;
    vector<int> sizes;
    int basdf = 0;
    int sum = 0;
    while (pos < n) {
        int cnt = 1;
        int p = pos;
        while (index[p] == -1) {
            index[p] = cnt;
            explored[p] = basdf;
            cnt++;
            p = arr[p];
        }
        if (explored[p] == basdf) {
            int sz = cnt - index[p];
            sizes.push_back(sz);
            sum += sz;
        }
        while (pos < n && index[pos] != -1) pos++;
        basdf++;
    }
    long long ans = 1;
    for (int sz : sizes) {
        long long asdf = 1;
        for (int i = 0; i < sz; i++) {
            asdf *= 2;
            asdf %= mod;
        }
        ans *= asdf - 2;
        ans %= mod;
    }
    for (int i = 0; i < n - sum; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}