#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << min((n - 1) * min(a, b), min(a, b) + max(n - 2, 0) * c) << endl;
    return 0;
}