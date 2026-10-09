#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int nums[n];
    k--;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i : nums) {
        if (i >= nums[k] && i > 0) {
            ret++;
        }
    }
    cout << ret << endl;
}