#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long minB = 10000000000000;
        int nums[n];
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            minB = min(minB, nums[i] + k);
        }
        for (int i = 0; i < n; i++) {
            if (abs(nums[i] - minB) > k) {
                minB = -1;
                break;
            }
        }
        cout << minB << endl;
    }
    return 0;
}