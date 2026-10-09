//
// Created by JMKov on 8/22/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[3000][100004];
//int smallestFact[5000004];

//void sieve(int n) {
//    for (int i = 2; i <= n; i++) {
//        if (smallestFact[i] != 0) continue;
//        for (int j = i; j <= n; j += i) {
//            smallestFact[j] = i;
//        }
//    }
//}

vector<int> fact(int v) {
    vector<int> ret;
    for (int i = 1; i * i <= v; i++) {
        if (v % i == 0) {
            ret.push_back(i);
            if (v / i != i) ret.push_back(v / i);
        }
    }
    return ret;
}

int main() {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return 0;
}