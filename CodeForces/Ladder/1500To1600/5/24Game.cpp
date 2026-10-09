//
// Created by JMKov on 5/6/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (n % 2 == 1) {
        cout << "5 - 2 = 3" << endl;
        cout << "3 - 1 = 2" << endl;
    }
    else {
        cout << "1 * 2 = 2" << endl;
    }
    cout << "2 * 3 = 6" << endl << "6 * 4 = 24" << endl;
    int count = 0;
    for (int i = (n % 2 == 1 ? 6 : 5); i <= n - 1; i += 2) {
        count++;
        cout << i + 1 << " - " << i << " = 1" << endl;
    }
    for (int i = 0; i < count; i++) {
        cout << "24 * 1 = 24" << endl;
    }
    return 0;
}
// 1 NO
// 2 NO
// 3 NO
// 4 YES
// 5 YES
// 6 YES

// 8 YES

// 10 YES