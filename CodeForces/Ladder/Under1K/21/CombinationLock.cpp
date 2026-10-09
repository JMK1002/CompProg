#include <string>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(a[i] - b[i]);
        sum += min(diff, 10 - diff);
    }
    cout << sum << endl;
}