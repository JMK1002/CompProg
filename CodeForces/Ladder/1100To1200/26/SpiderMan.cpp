#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tests[n];
    bool results[n] = { false };
    int evenNums = 0;
    for (int i = 0; i < n; i++) {
        cin >> tests[i];
        evenNums += tests[i] % 2 == 0;
        cout << (evenNums % 2 == 0) + 1 << endl;
    }
    return 0;
}