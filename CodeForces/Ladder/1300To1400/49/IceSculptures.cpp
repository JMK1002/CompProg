//
// Created by JMKov on 4/17/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = -1000000000;
    for (int i = 1; i <= n / 3; i++) {
        if (n % i != 0) {
            continue;
        }
        for (int x = 0; x < i; x++) {
            int s = 0;
            for (int j = i - 1; j < n; j += i) {
                s += arr[(j + x) % n];
            }
            ans = max(ans, s);
//            cout << x << " " << i << " " << s << endl;
        }
    }
    cout << ans << endl;
    return 0;
}