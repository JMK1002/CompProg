//
// Created by JMKov on 7/15/2023.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, bool> isPrime;
map<int, int> primeCount;

vector<int> sieve(int n) {
    vector<int> ans;
    vector<bool> explored(n);
    int count = 0;
    for (int i = 0; i < n; i++) explored[i] = false;
    for (int i = 2; i <= n; i++) {
        if (explored[i]) continue;
        isPrime[i] = true;
        ans.push_back(i);
        count++;
        primeCount[i] = count;
        for (int j = i; j <= n; j += i) {
            explored[j] = true;
        }
    }
    return ans;
}

int main() {
    vector<int> primes = sieve(2750131);
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < 2 * n; i++) {
        int u;
        cin >> u;
        ms.insert(u);
    }
    while (!ms.empty()) {
        auto p = ms.end();
        p--;
//        cout << *p << endl;
        int v = *p;
        if (isPrime[v]) {
            cout << primeCount[v] << " ";
            ms.erase(ms.lower_bound(primeCount[v]));
        }
        else {
            for (int j : primes) {
                if (v % j == 0) {
                    ms.erase(ms.lower_bound(v / j));
                    cout << v << " ";
                    break;
                }
            }
        }
        ms.erase(ms.lower_bound(v));
    }
    return 0;
}