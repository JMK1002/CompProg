//
// Created by JMKov on 6/22/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a & 1) odd++;
            else even++;
        }
        if (odd % 4 == 3 || odd % 4 == 0 || odd % 4 == 1 && even % 2 == 1) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
// 1 odd 0 even: Bob
// 1 odd 1 even: Alice
// 1 odd 2 even: Bob
// 1 odd 3 even: Alice
// ...
// 2 odd: Bob
// 3 odd: Alice
// 4 odd: Alice
// 5 odd 0 even: Bob
// 5 odd 1 even: Alice
// 5 odd 2 even: Bob
// 5 odd 3 even: Alice
// ...
// 6 odd 0 even: Bob
// 6 odd 1 even: Bob

// 1 1 1 1 1 1 2
// A B B A A B B
// A A B A A A B
// A B B A A B B
// A A B A A A B