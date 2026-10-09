//
// Created by JMKov on 6/8/2023.
//
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int t[n];
    map<int, multiset<int>> levelTimes;
    set<int> ballz;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        levelTimes[arr[i]].insert(t[i]);
        ballz.insert(arr[i]);
    }
    long long ans = 0;
    for (int i : ballz) {
        multiset<int> holding;
        long long sum = 0;
        int j = 0;
        do {
            for (int k : levelTimes[i + j]) {
                sum += k;
                holding.insert(k);
            }
            auto ptr = holding.end();
            ptr--;
            sum -= *ptr;
            ans += sum;
            multiset<int> asdf;
            asdf.insert(*ptr);
            levelTimes[i + j] = asdf;
            holding.erase(ptr);
            j++;
        } while (!holding.empty());
    }
    cout << ans << endl;
    return 0;
}