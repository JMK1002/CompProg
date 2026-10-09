//
// Created by JMKov on 6/4/2023.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <cstring>

using namespace std;

vector<int> SieveOfEratosthenes(int n) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) ans.push_back(i);
    }
    return ans;
}

bool prime(int n, const vector<int>& primes) {
    for (int i : primes) {
        if (n % i == 0 && n != i) return false;
    }
    return true;
}

int main() {
    // why is this not doing the do
    int n;
    cin >> n;
    vector<int> primes = SieveOfEratosthenes(1000000);
    if (prime(n, primes)) {
        cout << 1 << endl;
    }
    else if (n & 1) {
        cout << ((prime(n - 2, primes)) ? 2 : 3) << endl;
    }
    else {
        cout << 2 << endl;
    }

//    for (int v = 2; v < 1000; v++) {
//        int count = 0;
//        int n = v;
//        for (int i = primes.size() - 1; i >= 0; i--) {
//            if (primes[i] < n) {
//                n -= primes[i];
//                count++;
//            }
//        }
//        cout << count << " ";
//    }
    return 0;
}