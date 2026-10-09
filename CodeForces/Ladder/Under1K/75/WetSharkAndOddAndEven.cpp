#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    long long minOdd = 1000000000000;
    while (n--) {
        long long a;
        cin >> a;
        if (a % 2 == 1 && a < minOdd) {
            minOdd = a;
        }
        sum += a;
    }
    if (sum % 2 == 0) {
        cout << sum << endl;
    }
    else {
        cout << sum - minOdd << endl;
    }
    return 0;
}