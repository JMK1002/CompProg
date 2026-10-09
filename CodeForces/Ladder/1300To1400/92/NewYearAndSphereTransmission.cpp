//
// Created by JMKov on 5/2/2023.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <queue>
#include <set>
using namespace std;

vector<int> primeSieve(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 2);
    for (int i = 0; i < (n); i++) {
        if (arr[i] != i + 2) {
            continue;
        }
        int val = arr[i];
        for (int j = i + val; j < arr.size(); j += val) {
            arr[j] = 0;
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            arr.erase(arr.begin() + i);
            i--;
        }
    }
    return arr;
}

int main() {
    int n;
    cin >> n;
    long long asdf = n;
    vector<int> primes = primeSieve(32000);
//    cout << primes.size() << endl;
    int divisors[primes.size()];
    vector<int> primeFactors;
    set<long long> out;
    for (int i = 0; i < primes.size(); i++) {
        divisors[i] = 0;
    }
    int ptr = 0;
    while (ptr < primes.size()) {
        if (n % primes[ptr] == 0) {
            if (divisors[ptr] == 0) {
                primeFactors.push_back(ptr);
            }
            n /= primes[ptr];
            divisors[ptr]++;
        }
        else {
            ptr++;
        }
    }
    queue<int> q;
    ptr = 0;
    q.push(1);
//    cout << primeFactors.size() << endl;
//    for (int i = 0; i < primeFactors.size(); i++) {
//        cout << primeFactors[i] << " " << primes[primeFactors[i]] << endl;
//    }
//    cout << divisors[primeFactors[0]] << endl;
    while (!q.empty() && ptr != primeFactors.size()) {
        int m = q.size();
        for (int i = 0; i < m; i++) {
            int val = q.front();
            q.pop();
            int a = 1;
            for (int j = 0; j <= divisors[primeFactors[ptr]]; j++) {
                q.push(a * val);
//                cout << a * val << " ";
                a *= primes[primeFactors[ptr]];
            }
        }
//        cout << endl;
        ptr++;
    }
    int m = q.size();
    for (int i = 0; i < m; i++) {
        int val = q.front();
        q.pop();
        int a = 1;
        for (int j = 0; j <= 1; j++) {
            q.push(a * val);
            a *= n;
        }
    }
    while (!q.empty()) {
        long long v = q.front();
        out.insert((1 + (asdf - v + 1)) * (asdf / v) / 2);
        q.pop();
    }
    for (long long i : out) {
        cout << i << " ";
    }
    return 0;
}