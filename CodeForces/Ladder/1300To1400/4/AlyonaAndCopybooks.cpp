//
// Created by JMKov on 4/2/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    long long costs[3];
    cin >> n >> costs[0] >> costs[1] >> costs[2];
    if (n % 4 == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = LONG_LONG_MAX;
    switch (n % 4) {
        case 1:
            ans = min(ans, costs[0] * 3);
            ans = min(ans, costs[0] + costs[1]);
            ans = min(ans, costs[2]);
            break;
        case 2:
            ans = min(ans, costs[0] * 2);
            ans = min(ans, costs[1]);
            ans = min(ans, costs[2] * 2);
            break;
        case 3:
            ans = min(ans, costs[0]);
            ans = min(ans, costs[1] + 3 * costs[0]);
            ans = min(ans, costs[1] + costs[2]);
            ans = min(ans, costs[2] * 3);
            break;
    }
    cout << ans << endl;
    return 0;
}