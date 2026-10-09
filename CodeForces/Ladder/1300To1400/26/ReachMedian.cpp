//
// Created by JMKov on 4/10/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    int index = n;
    int mid = n / 2;
    for (int i = 0; i < n; i++) {
        if (a[i] > s) {
            index = i;
            break;
        }
    }
    for (int i = min(mid, index); i < max(mid + 1, index); i++) {
        ans += abs(s - a[i]);
    }
//    cout << index << " " << mid << endl;
    cout << ans << endl;
    return 0;
}

//11 12 12 15 19 20 21   0
//10 11 12 12 20 20 21   5
//10 10 11 12 20 20 21   7