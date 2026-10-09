//
// Created by JMKov on 2/10/2024.
//
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int ans = 0;
int arr[100001];
int cnt[100001];
int lowDiv[100001];
vector<int> primes;

void sieve(int n) {
    for (int i = 2; i < n; i++) {
        if (lowDiv[i]) continue;
        lowDiv[i] = 1;
        primes.push_back(i);
        for (int j = i * 2; j < n; j += n) {
            lowDiv[j] = i;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        set<int> divs;
        for (int j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                divs.insert(j);
                divs.insert(arr[i] / j);
            }
        }
        for (int j : divs) lowDiv
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}