#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ret = 0;
    for (int a = 0; pow(a, 2) <= n; a++) {
        int asqr = pow(a, 2);
        int b = n - asqr;
        if (pow(b, 2) + a == m) {
            ret++;
        }
    }
    cout << ret << endl;
}