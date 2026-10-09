//
// Created by JMKov on 12/8/2023.
//
#include <map>
#include <iostream>
using namespace std;

long long startSum[10010];
long long endSum[10010];
long long startCnt[5002];
long long endCnt[5002];

int main() {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        startCnt[u]++;
        endCnt[v]++;
    }
    for (long long i = 0; i < 5002; i++) {
        for (long long j = 0; j < 5002; j++) {
            startSum[i + j] += startCnt[i] * startCnt[j];
            endSum[i + j] += endCnt[i] * endCnt[j];
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= m * 2; i++) {
        ans += startSum[i];
        if (i != 0) ans -= endSum[i - 1];
        cout << ans << endl;
    }
    return 0;
}