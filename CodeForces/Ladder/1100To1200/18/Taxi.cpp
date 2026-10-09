#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[4] = { 0 };
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums[a - 1]++;
    }
    int prevRet = -1;
    while (prevRet != ret) {
        prevRet = ret;
        ret = 0;
        int a = min(nums[0], nums[2]);
        nums[0] -= a;
        nums[2] -= a;
        nums[3] += a;
        nums[3] += nums[1] / 2;
        nums[1] %= 2;
        a = min(nums[0], nums[1]);
        nums[0] -= a;
        nums[1] -= a;
        nums[2] += a;
        a = min(nums[0], nums[2]);
        nums[0] -= a;
        nums[2] -= a;
        nums[3] += a;
        nums[1] += nums[0] / 2;
        nums[0] %= 2;
        for (int i = 0; i < 4; i++) {
            ret += nums[i];
        }
    }
    cout << ret << endl;
    return 0;
}