//
// Created by JMKov on 4/15/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = n;
    int a = 0;
    while (m - max(ans - a, 0) * 2 - a < 0) {
        ans--;
        a++;
        if (ans - a < 0) {
            ans = 1000000000;
            break;
        }
    }
    int newAns = m;
    int newA = 0;
    while (n - max(newAns - newA, 0) * 2 - newA < 0) {
        newAns--;
        newA++;
        if (newAns - newA < 0) {
            newAns = 1000000000;
            break;
        }
    }

    if (min(ans, newAns) == 1000000000) {
        cout << 0 << endl;
        return 0;
    }
    cout << min(ans, newAns) << endl;
    return 0;
}