#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int rangeSum = n * (n + 1) / 2;
    bool nums[n + 1] = { false };
    for (int i = 2; i < n; i++) {
        if (__gcd(i, rangeSum - i) > 1) {
            cout << "Yes" << endl;
            int a = 0;
            int count = 0;
            for (int j = 1; a < i; j++) {
                a += j;
                nums[j] = true;
                count = j;
            }
            nums[a - i] = false;
            count -= (a - i) != 0;
            cout << count << " ";
            for (int j = 1; j <= n; j++) {
                if (nums[j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
            cout << n - count << " ";
            for (int j = 1; j <= n; j++) {
                if (!nums[j]) {
                    cout << j << " ";
                }
            }
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}