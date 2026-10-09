//
// Created by JMKov on 4/20/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int primeCount = 0;
    int val = 1;
    for (int i = 0; i < 24; i++) {
        if (primes[i] * val > 100 || (primeCount == 0 && i > 3)) {
            break;
        }
        cout << primes[i] * val << endl;
        std::fflush(stdout);
        string s;
        cin >> s;
        if (s == "yes") {
            primeCount++;
            val *= primes[i];
            i--;
        }
    }
    if (primeCount >= 2) {
        cout << "composite" << endl;
    }
    else {
        cout << "prime" << endl;
    }
    return 0;
}