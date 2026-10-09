//
// Created by JMKov on 8/7/2023.
//
#include <iostream>
using namespace std;

int ans = 2;
int cnt = 0;

bool comp(long long a, long long b) {
//    cnt++;
    cout << "? " << a << " " << b << endl;
//    cout << a % ans << " " << b % ans << endl;
    cout.flush();
    char c;
    cin >> c;
    if (c == 'x') return true;
    else return false;
//    return (a % ans >= b % ans);
}

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "end") {
            break;
        }
        long long x = 1;
        long long y = 0;
        while (x < 2000000000 && comp(x, y)) {
            y = x;
            x *= 2;
        }
        if (x > 2000000000) {
            cout << "! 1" << endl;
            cout.flush();
            continue;
        }
        int low = y;
        int high = x;
        while (low < high - 1) {
            int mid = (low + high) / 2;
            if (comp(mid, low)) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
//        low += comp(low, 1);
        low++;
//        if (ans != low) {
        cout << "! " << low << endl;
//            cout << "SDF" << ans << endl;
//        }
//        cout << ans << endl;
        cout.flush();
//        cout << cnt << endl;
//        ans++;
//        break;
    }
    return 0;
}