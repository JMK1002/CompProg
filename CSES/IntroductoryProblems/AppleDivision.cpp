//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

long long arr[20];
long long n;

long long solve(long long ind, long long sum) {
    if (ind == n) return abs(sum);
    return min(solve(ind + 1, sum + arr[ind]), solve(ind + 1, sum - arr[ind]));
}

int main() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    cout << solve(0, 0) << endl;
    return 0;
}