//
// Created by JMKov on 1/28/2024.
//
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime(1000000, true);

void sieve(int v) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= v; i++) {
        if (isPrime[i] && (long long)i * i <= v) {
            for (int j = i * i; j <= v; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {

    return 0;
}