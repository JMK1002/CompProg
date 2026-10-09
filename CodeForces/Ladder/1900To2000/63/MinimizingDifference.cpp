//
// Created by JMKov on 8/14/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long a = 1;
    long long b = 1;
    while (a < n && arr[0] == arr[a]) a++;
    while (b < n && arr[n - 1] == arr[n - b - 1]) b++;
    long long diff = arr[n - 1] - arr[0];
    while (k / min(a, b) > 0) {
        if (a <= b) {
            if ((arr[a] - arr[a - 1]) * a > k) {
                diff -= k / a;
                arr[a - 1] += k / a;
                k -= k / a * a;
            }
            else {
                diff -= arr[a] - arr[a - 1];
                k -= (arr[a] - arr[a - 1]) * a;
                a++;
            }
        }
        else {
            if ((arr[n - b] - arr[n - b - 1]) * b > k) {
                diff -= k / b;
                arr[n - b - 1] -= k / b;
                k -= k / b * b;
            }
            else {
                diff -= arr[n - b] - arr[n - b - 1];
                k -= (arr[n - b] - arr[n - b - 1]) * b;
                b++;
            }
        }
    }
    cout << max((long long) 0, diff) << endl;
    return 0;
}