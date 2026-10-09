#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long x = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    for (int i = n - 1; i >= n / 2; i--) {
        x += a[i];
    }
    cout << (long long) (pow(x, 2) + pow(sum - x, 2)) << endl;
    return 0;
}