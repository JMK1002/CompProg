//
// Created by JMKov on 4/16/2023.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
using namespace std;

vector<int> assignmentSieve(int n) {
    vector<int> arr(n - 1);
    iota(arr.begin(), arr.end(), 2);
    for (int i = 0; i < sqrt(n); i++) {
        if (arr[i] != i + 2) {
            continue;
        }
        int val = arr[i];
        for (int j = i + val; j < arr.size(); j += val) {
            arr[j] = val;
        }
    }
    return arr;
}

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> arr = assignmentSieve(n);
    vector<int> primes = arr;
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (primes[i - count] != i + 2) {
            primes.erase(primes.begin() + i - count);
            count++;
        }
    }
    for (int i = 0; i < primes.size(); i++) {
        mp[primes[i]] = i;
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << mp[arr[i]] + 1 << " ";
    }
    return 0;
}