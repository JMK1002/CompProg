//
// Created by JMKov on 5/17/2023.
//
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> sieve(int n) {
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 2);
    for (int i = 0; i * i - 10 < n; i++) {
        if (ans[i] == 0) {
            continue;
        }
        int v = ans[i];
        for (int j = i + v; j < n; j += v) {
            ans[j] = 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == 0) {
            ans.erase(ans.begin() + i);
            i--;
        }
    }
    return ans;
}

int main() {
    vector<int> primes = sieve(7000);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = 1;
        while (x <= n) {
            x *= 2;
        }
        if (x == (n + 1)) {
            int count = 0;
            while (count != primes.size() && n % primes[count] != 0) count++;
            if (count >= primes.size()){
                cout << 1 << endl;
            }
            else {
                cout << n / primes[count] << endl;
            }
        }
        else {
            cout << x - 1 << endl;
        }
    }
    return 0;
}