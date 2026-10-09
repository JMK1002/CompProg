#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        count += a > 0;
        neg += a < 0;
    }
    cout << (count >= (n - n / 2)) + ((neg >= (n - n / 2))) * (count < (n - n / 2)) * -1 << endl;
    return 0;
}