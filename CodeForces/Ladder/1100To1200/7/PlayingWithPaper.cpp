#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long count = 0;
    long long c = max(a, b);
    b = min(a, b);
    a = c;
    while (a > 1 || b > 1) {
        count += a / b;
        a %= b;
        if (b <= 1 || a == 0) {
            break;
        }
        count += b / a;
        b %= a;
        if (a <= 1 || b == 0) {
            break;
        }
    }
    cout << count << endl;
    return 0;
}